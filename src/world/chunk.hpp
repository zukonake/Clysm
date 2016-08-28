#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <cstdint>
//
#include <world/tile.hpp>

struct Chunk
{
	typedef Tile[ mSize ][ mSize ] TileArray;
	const static uint16_t mSize = 128;
	TileArray tiles;
};

#endif
