#include "worldGenerator.hpp"
//
#include <core/dataset.hpp>

WorldGenerator::WorldGenerator( int32_t seed, const Dataset& dataset ) :
	mSeed( seed ),
	mDataset( dataset )
{
	//TODO initialize modules
}

Chunk WorldGenerator::generateChunk( const Point& chunkPosition )
{
	Chunk returnValue;
	return returnValue;
}

const int32_t& WorldGenerator::getSeed() const noexcept
{
	return mSeed;
}

Chunk::Field WorldGenerator::generateField( const Point& tilePosition )
{
	Chunk::Field returnValue;
	returnValue.first = nullptr;
	returnValue.second = new Tile( mDataset.getObject< TileSubtype >( "grass" ));
	return returnValue;
}
