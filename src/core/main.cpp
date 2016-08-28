#include <iostream>
#include <string>
#include <ext/luaWrapper.hpp>
#include <core/client.hpp>
#include <core/server.hpp>

int main( int argc, char* argv[] )
{
	Client localClient( { 800, 600 }, "ClysmClient" );
	Server* localServer = new Server();
	localClient.connect( localServer );
	try
	{
		while( localClient.isConnected() )
		{
			localServer->loop();
		}
	}
	catch( std::exception& e )
	{
		std::cerr << "main: Unhandled exception: " << e.what() << "\n";
	}
	delete localServer;
	return 0;
}
