#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <geometry/point.hpp>
#include <geometry/direction.hpp>

class EntitySubtype;
class World;

class Entity
{
public:
	Entity( const Point& position, World* world, const EntitySubtype* subtype );
	virtual ~Entity() = default;

	Point move( Direction direction );
	Point teleport( Point position );
private:
	Point mPosition;
	World* mWorld = nullptr;
	const EntitySubtype* mSubtype = nullptr;
};

#endif
