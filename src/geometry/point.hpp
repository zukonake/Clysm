#ifndef POINT_HPP
#define POINT_HPP

#include <functional>
#include <cstdint>
#include <iostream>
#include <SFML/System/Vector2.hpp>

struct Direction;

struct Point
{
	friend std::ostream& operator<<( std::ostream& out, const Point& obj );
	friend std::istream& operator>>( std::istream& in, Point& obj );
	typedef int32_t coordinate;

	Point( const coordinate& x, const coordinate& y ) noexcept : x( x ), y( y ) { }
	explicit Point( std::istream& in ) noexcept;
	Point( const sf::Vector2< float >& that ) noexcept;
	Point( const sf::Vector2< int >& that ) noexcept;
	Point( const sf::Vector2< unsigned int >& that ) noexcept;
	Point() noexcept : x( 0 ), y ( 0 ) { }

	virtual ~Point() = default;

	virtual operator sf::Vector2< float >() const noexcept;
	virtual operator sf::Vector2< int >() const noexcept;

	virtual Point operator*( const Point& mul ) const noexcept;
	virtual Point operator/( const Point& div ) const noexcept;
	virtual Point operator%( const Point& mod ) const noexcept;
	virtual Point operator+( const Point& add ) const noexcept;
	virtual Point operator-( const Point& sub ) const noexcept;
	virtual Point operator*( const int& mul ) const noexcept;
	virtual Point operator/( const int& div ) const noexcept;
	virtual Point operator%( const int& mod ) const noexcept;
	virtual Point operator+( const int& add ) const noexcept;
	virtual Point operator-( const int& sub ) const noexcept;

	virtual Point& operator=( const Point& that ) = default;

	virtual bool operator==( const Point& target ) const noexcept;
	virtual bool operator<=( const Point& target ) const noexcept;
	virtual bool operator<( const Point& target ) const noexcept;
	virtual bool operator>( const Point& target ) const noexcept;
	virtual bool operator>=( const Point& target ) const noexcept;

	Point move( const Direction& direction, const int& difference = 1 ) noexcept;

	static Point tilePosition( const Point& that, const uint16_t& sizeInTiles );
	static Point chunkPosition( const Point& that,const uint16_t& sizeInTiles );
	static Point internalPosition( const Point& that,const uint16_t& sizeInTiles );

	coordinate x;
	coordinate y;
};

struct PointHasher
{
	std::size_t operator()( const Point& k ) const
	{
		return ( ( std::hash< Point::coordinate >()( k.x ) xor
			( std::hash< Point::coordinate >()( k.y ) << 1 ) ) >> 1 );
  }
};

#endif
