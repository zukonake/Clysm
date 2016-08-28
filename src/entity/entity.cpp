#include "entity.hpp"

Entity::Entity( const Point& position, World* world, const EntitySubtype* subtype ) :
	mPosition( position ),
	mWorld( world ),
	mSubtype( subtype )
{

}
