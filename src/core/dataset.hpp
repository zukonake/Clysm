#ifndef DATASET_HPP
#define DATASET_HPP

#include <cstdint>
#include <string>
#include <unordered_map>
#include <iostream>
#include <exception>
//
#include <luaPP.hpp>
//
#include <ext/fileSystemAdapter.hpp>
#include <ext/loadable.hpp>
#include <entity/entitySubtype.hpp>
#include <tile/tileSubtype.hpp>

class Loadable;

class Dataset
{
	const std::string mDatasetPath = "dataset/";
	const std::string mConfigPath = "config.lua";
public:
	Dataset();
	~Dataset();

	template < typename T = Loadable >
	const T* getObject( const std::string& key ) const;
	template < typename T >
	const T* getConfig( const std::string& key ) const;
private:
	template< typename T >
	void initializeObjects( const std::string& directoryPath );
	void loadConfig();

	const LPP::Table* mConfig = nullptr;
	std::unordered_map< std::string, Loadable* > mObjects;
	FileSystemAdapter mFileSystem;
	LPP::LuaStack luaStack;
	const LPP::Function* mConfigFile = nullptr;
};

template < typename T >
const T* Dataset::getObject( const std::string& key ) const
{
	return dynamic_cast< const T* >( mObjects.at( key ));
}

template < typename T >
const T* Dataset::getConfig( const std::string& key ) const
{
	return mConfig->at< T >( key );
}

template< typename T >
void Dataset::initializeObjects( const std::string& directoryPath )
{
	std::unordered_map< std::string, Loadable* > output;
	try
	{
		for( auto iFile : mFileSystem.listFiles( directoryPath ) )
		{
			LPP::Function* script = luaStack.loadFile( iFile );
			luaStack.call();
			luaStack.loadGlobals();
			output[ *luaStack.at< LPP::String >( "loadableName" ) ] = new T( luaStack.getGlobals() );
			delete script;
		}
	}
	catch( std::exception& e)
	{
		std::cerr << "Dataset::initializeObjects: Unhandled exception: " << e.what() << "\n";
	}
	mObjects.insert( output.begin(), output.end());
}

#endif
