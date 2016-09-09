#ifndef OUTPUTDATA_HPP
#define OUTPUTDATA_HPP

#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
//
#include <rendering/tileMap.hpp>

struct OutputData
{
	bool end = false;
	TileMap tileMap;
};

#endif
