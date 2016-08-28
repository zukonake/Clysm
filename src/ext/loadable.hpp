#ifndef LOADABLE_HPP
#define LOADABLE_HPP

#include <lua5.2/lua.hpp>

class Loadable
{
protected:
	explicit Loadable( lua_State* luaState );
	virtual ~Loadable() = default;
};

#endif
