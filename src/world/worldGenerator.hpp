#ifndef WORLDGENERATOR_HPP
#define WORLDGENERATOR_HPP

#include <map>
#include <cstdint>
#include <noise/noise.h>
//
#include <world/chunk.hpp>

struct Point;
class Dataset;

class WorldGenerator
{
public:
	WorldGenerator( int32_t seed, const Dataset& dataset );

	Chunk generateChunk( const Point& chunkPosition );

	const int32_t& getSeed() const noexcept;
private:
	Chunk::Field generateField( const Point& tilePosition );

	int32_t mSeed;
	const Dataset& mDataset;
	std::map< std::string, noise::module::Module* > mModules;
};

#endif
