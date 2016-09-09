#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <map>
//
#include <SFML/Graphics/Vertex.hpp>
#include <geometry/point.hpp>

struct TileMap : std::map< Point, sf::Vertex[4] >
{
	using std::map< Point, sf::Vertex[4] >::operator[];

	TileMap( const Point& size = { 0, 0 }) noexcept;
};

#endif
