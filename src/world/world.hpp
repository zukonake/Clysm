#ifndef WORLD_HPP
#define WORLD_HPP

#include <unordered_map>
#include <map>
//
#include <geometry/point.hpp>
#include <world/chunk.hpp>
#include <world/worldGenerator.hpp>

class Tile;
class Entity;
class Dataset;

class World
{
public:
	World( const Dataset& dataset );

	Chunk::Field& operator[]( const Point& index );
private:
	std::unordered_map< Point, Chunk > mChunks;

	const Dataset& mDataset;
	WorldGenerator mGenerator;
};

#endif
