#ifndef LUAWRAPPER_HPP
#define LUAWRAPPER_HPP

#include <string>
#include <unordered_map>
#include <lua5.2/lua.hpp>
#include <boost/variant.hpp>
#include <geometry/point.hpp>

//TODO add lua tables compatibility

class LuaWrapper
{
public:
	typedef boost::variant< int, double, std::string, Point > LuaType;
	typedef std::unordered_map< std::string, LuaType > LuaTable;

	LuaWrapper() noexcept;
	~LuaWrapper();

	void openScript( std::string filePath );
	void executeScript( std::string filePath ); //TODO add arguments
	void executeCurrentScript();                //
	void throwException();

	LuaType getVariable( std::string variableName );
	LuaTable getTable( std::string tableName );
	LuaType callFunction( std::string functionName );
	LuaType evaluate( std::string expression );
private:
	LuaType convertVariable( int index, int popIndex = 1 );

	lua_State* mLuaState = nullptr;
};

#endif
