#include "direction.hpp"

Direction::operator DirectionType() const noexcept
{
	return type;
}

void Direction::rotateClockwise() noexcept
{
	if( type == DirectionType::NORTH )
	{
		type = DirectionType::EAST;
	}
	else
	{
		type = static_cast< DirectionType >( ( int )type - 1 );
	}
}

void Direction::rotateCounterClockwise() noexcept
{
	if( type == DirectionType::EAST )
	{
		type = DirectionType::NORTH;
	}
	else
	{
		type = static_cast< DirectionType >( ( int )type + 1 );
	}
}
