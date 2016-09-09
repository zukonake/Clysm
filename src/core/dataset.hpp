#ifndef DATASET_HPP
#define DATASET_HPP

#include <cstdint>
#include <string>
#include <unordered_map>
#include <array>
//
#include <ext/fileSystemAdapter.hpp>
#include <ext/luaWrapper.hpp>

class Loadable;

class Dataset
{
	const std::array< std::string, 2 > mDirectories = {{ "entitySubtype", "tileSubtype" }};
	const std::string mDatasetPath = "dataset/";
	const std::string mConfigFile = "config.lua";
public:
	Dataset();
	~Dataset();

	const Loadable* getObject( const std::string& key ) const;
	template < typename T >
	const T& getConfigField( const std::string& key ) const;
private:
	std::unordered_map< std::string, Loadable* > initializeObjects( const std::string& directoryPath );
	void loadConfig();

	LuaWrapper::LuaTable mConfig;
	std::unordered_map< std::string, Loadable* > mObjects;
	FileSystemAdapter mFileSystem;
	LuaWrapper luaWrapper;
};

template < typename T >
const T& Dataset::getConfigField( const std::string& key ) const
{
	return boost::get< T > ( mConfig.at( key ));
}

#endif
