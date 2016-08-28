#ifndef DIRECTION_HPP
#define DIRECTION_HPP

enum class DirectionType
{
	NORTH = 0,
	WEST = 1,
	SOUTH = 2,
	EAST = 3
};

struct Direction
{
	Direction( DirectionType type ) noexcept : type( type ) { }

	virtual operator DirectionType() const noexcept;

	virtual void rotateClockwise() noexcept;
	virtual void rotateCounterClockwise() noexcept;

	DirectionType type;
};

#endif
