#include <string>
#include <utility>
#include <lua5.2/lua.hpp>
#include <boost/variant.hpp>

//TODO add lua tables compatibility

class LuaWrapper
{
public:
	typedef boost::variant< bool, int, std::string > LuaType;

	LuaWrapper() noexcept;
	~LuaWrapper();

	void openScript( std::string filePath );
	void executeScript( std::string filePath ); //TODO add arguments
	void executeCurrentScript();                //
	void throwException();

	LuaType getVariable( std::string variableName );
	LuaType callFunction( std::string functionName );
	LuaType evaluate( std::string expression );
private:
	LuaType convertVariable( int index );

	lua_State* mLuaState = nullptr;
};
