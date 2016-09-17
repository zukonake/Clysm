#ifndef TILESUBTYPE_HPP
#define TILESUBTYPE_HPP

#include <ext/loadable.hpp>

class TileSubtype : public Loadable
{
public:
	TileSubtype( const LPP::Table* table );
};

#endif
