#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <cstdint>
#include <utility>
#include <boost/optional.hpp>
//
#include <geometry/point.hpp>
#include <tile/tile.hpp>
#include <entity/entity.hpp>

struct Chunk
{
	typedef std::pair< Entity*, Tile* > Field;
	constexpr static Point::coordinate size = 128;

	Chunk();
	~Chunk();

	Field fields[ size ][ size ]; //"tiles" is not std::unordered_map< Point, Tile > for effiency
};

#endif
