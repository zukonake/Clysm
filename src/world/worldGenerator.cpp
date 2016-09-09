#include "worldGenerator.hpp"

WorldGenerator::WorldGenerator( int32_t seed, const Dataset& dataset ) :
	mSeed( seed ),
	mDataset( dataset )
{
	//TODO initialize modules
}

Chunk WorldGenerator::generateChunk( const Point& chunkPosition )
{
	return Chunk();
}

const int32_t& WorldGenerator::getSeed() const noexcept
{
	return mSeed;
}

Chunk::Field WorldGenerator::generateField( const Point& tilePosition )
{
	return Chunk::Field();
}
