#ifndef TILE_HPP
#define TILE_HPP

class TileSubtype;

class Tile
{
public:
	Tile( const TileSubtype* subtype );
private:
	const TileSubtype* mSubtype;
};

#endif
