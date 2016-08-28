#include "luaWrapper.hpp"
#include <stdexcept>

LuaWrapper::LuaWrapper() noexcept :
	mLuaState( luaL_newstate() )
{
	luaL_openlibs( mLuaState );
}

LuaWrapper::~LuaWrapper()
{
	lua_close( mLuaState );
}

void LuaWrapper::openScript( std::string filePath )
{
	if( luaL_loadfile( mLuaState, filePath.c_str() ) != LUA_OK )
	{
		throwException();
	}
}

void LuaWrapper::executeScript( std::string filePath )
{
	if( luaL_dofile( mLuaState, filePath.c_str() ) != LUA_OK )
	{
		throwException();
	}
}

void LuaWrapper::executeCurrentScript()
{
	if( lua_pcall( mLuaState, 0, LUA_MULTRET, 0) != LUA_OK )
	{
		throwException();
	}
}

void LuaWrapper::throwException()
{
	throw std::runtime_error( lua_tostring( mLuaState, -1 ) );
	lua_pop( mLuaState, 1 );
}

LuaWrapper::LuaType LuaWrapper::getVariable( std::string variableName )
{
	lua_getglobal( mLuaState, variableName.c_str() );
	return convertVariable( -1 );
}

LuaWrapper::LuaType LuaWrapper::evaluate( std::string expression )
{
	lua_pushfstring( mLuaState, "return %s", expression.c_str() );
	luaL_loadstring( mLuaState, lua_tostring( mLuaState, -1 ) );
	lua_remove( mLuaState, -2 );
	if( lua_pcall( mLuaState, 0, 1, 0 ) != LUA_OK )
	{
		throwException();
	}
	return convertVariable( -1 );
}

LuaWrapper::LuaType LuaWrapper::convertVariable( int index )
{
	if( lua_isboolean( mLuaState, index ))
	{
		return ( bool )lua_toboolean( mLuaState, index );
	}
	else if( lua_isnumber( mLuaState, index ))
	{
		return ( int )lua_tonumber( mLuaState, index );
	}
	else if( lua_isstring( mLuaState, index ))
	{
		return ( std::string )lua_tostring( mLuaState, index );
	}
	return 0;
}
