#include "tileMap.hpp"
#include <cstdint>

TileMap::TileMap( const Point& size ) noexcept
{
	for( uint16_t iY = 0; iY < size.y; iY++ )
	{
		for( uint16_t iX = 0; iX < size.x; iX++ )
		{
			//this->operator[]({ iX, iY })[] = ;
		}
	}
}
