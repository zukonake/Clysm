#include "luaWrapper.hpp"
#include <stdexcept>
#include <cassert>

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

LuaWrapper::LuaTable LuaWrapper::getTable( std::string tableName )
{
	LuaTable returnValue;
	lua_getglobal( mLuaState, tableName.c_str());
	lua_pushnil( mLuaState );
	while( lua_next( mLuaState, -2 ))
	{
		returnValue[ lua_tostring( mLuaState, -2 ) ] = convertVariable( -1 );
	}
	lua_pop( mLuaState, 2 );
	return returnValue;
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

LuaWrapper::LuaType LuaWrapper::convertVariable( int index, int popIndex )
{
	LuaType value;
	if( lua_isnil( mLuaState, index ))
	{
		throw std::runtime_error( "LuaWrapper::convertVariable: attempting to convert a nil value\n" );
		value = 0;
	}
	else if( lua_isnumber( mLuaState, index ))
	{
		double temp = ( double )lua_tonumber( mLuaState, index );
		if ( temp - double( int( temp )) != 0.0 )
		{
			value = ( double )temp;
		}
		else
		{
			value = ( int )temp;
		}
	}
	else if( lua_isstring( mLuaState, index ))
	{
		value = ( std::string )lua_tostring( mLuaState, index );
	}
	else if( lua_istable( mLuaState, index ))
	{
		Point temp;
		lua_rawgeti( mLuaState, -1, 1 );
		temp.x = boost::get< int >( convertVariable( -1 ));
		lua_rawgeti( mLuaState, -1, 2 );
		temp.y = boost::get< int >( convertVariable( -1 ));
		value = temp;
	}
	lua_pop( mLuaState, popIndex );
	return value;
}
