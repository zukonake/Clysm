#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <cstdint>
#include <utility>
#include <boost/optional.hpp>
//
#include <world/tile.hpp>
#include <entity/entity.hpp>

struct Chunk
{
	typedef std::pair< boost::optional< Entity >, Tile > Field;
	const static uint16_t size = 128;
	Field fields[ size ][ size ]; //"tiles" is not std::unordered_map< Point, Tile > for effiency
};

#endif
