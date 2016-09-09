#include "dataset.hpp"
#include <iostream>
#include <exception>
//
#include <ext/loadable.hpp>

Dataset::Dataset()
{
	loadConfig();
	for( auto iFolder : mDirectories )
	{
		initializeObjects( iFolder );
	}
}

Dataset::~Dataset()
{
	for( auto iPair : mObjects )
	{
		delete iPair.second;
	}
}

const Loadable* Dataset::getObject( const std::string& key ) const
{
	return mObjects.at( key );
}

std::unordered_map< std::string, Loadable* > Dataset::initializeObjects( const std::string& directoryPath )
{
	std::unordered_map< std::string, Loadable* > output;
	try
	{
		/*for( auto iFile : mFileSystem.listFiles( mDatasetPath + getConfigField< std::string >( "datasetName" ) + directoryPath ) )
		{

		}*/
	}
	catch( std::exception& e)
	{
		std::cerr << "Dataset::initializeObjects: Unhandled exception: " << e.what() << "\n";
	}
	return output;
}

void Dataset::loadConfig()
{
	luaWrapper.executeScript( mDatasetPath + mConfigFile );
	mConfig = luaWrapper.getTable( "config" );
}
