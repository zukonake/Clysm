#include "chunk.hpp"

Chunk::Chunk()
{
	for( Point::coordinate iY = 0; iY < size; iY++ )
	{
		for( Point::coordinate iX = 0; iX < size; iX++ )
		{
			fields[ iX ][ iY ].first = nullptr;
			fields[ iX ][ iY ].second = nullptr;
		}
	}
}

Chunk::~Chunk()
{
	for( Point::coordinate iY = 0; iY < size; iY++ )
	{
		for( Point::coordinate iX = 0; iX < size; iX++ )
		{
			delete fields[ iX ][ iY ].first;
			delete fields[ iX ][ iY ].second;
		}
	}
}

const Point::coordinate Chunk::size;
