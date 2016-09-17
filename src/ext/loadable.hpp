#ifndef LOADABLE_HPP
#define LOADABLE_HPP

namespace LPP
{
	class Table;
}

class Loadable
{
public:
	Loadable() = delete;
	explicit Loadable( const LPP::Table* table ) { }

	virtual ~Loadable() = default;
};

#endif
