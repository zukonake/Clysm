#ifndef ENTITYSUBTYPE_HPP
#define ENTITYSUBTYPE_HPP

#include <ext/loadable.hpp>

class EntitySubtype : public Loadable
{
public:
	EntitySubtype( const LPP::Table* table );
};

#endif
