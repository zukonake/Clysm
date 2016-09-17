#ifndef OUTPUTDATA_HPP
#define OUTPUTDATA_HPP

#include <string>
//
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
//
#include <geometry/point.hpp>
#include <rendering/tileMap.hpp>

struct OutputData
{
	Point windowSize;
	std::string windowTitle;
	bool end = false;
	TileMap tileMap;
};

#endif
