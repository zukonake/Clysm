#include "dataset.hpp"
//
#include <entity/entitySubtype.hpp>
#include <tile/tileSubtype.hpp>

Dataset::Dataset()
{
	loadConfig();
	//std::string datasetName = getConfigField< std::string >( "datasetName" );
	//initializeObjects< EntitySubtype >( mDatasetPath + datasetName + "entitySubtype" );
	//initializeObjects< TileSubtype >( mDatasetPath + datasetName + "tileSubtype" );
}

Dataset::~Dataset()
{
	for( auto iPair : mObjects )
	{
		delete iPair.second;
	}
	delete mConfigFile;
	delete mConfig;
}

void Dataset::loadConfig()
{
	mConfigFile = luaStack.loadFile( mDatasetPath + mConfigPath );
	luaStack.call();
	luaStack.loadGlobal( "config" );
	mConfig = luaStack.get< const LPP::Table >();
}
