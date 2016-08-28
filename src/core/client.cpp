#include "client.hpp"
#include <core/server.hpp>
#include <rendering/renderData.hpp>

Client::Client( const Point& windowSize, const std::string& windowTitle ) :
	SFMLAdapter( windowSize, windowTitle )
{

}

Client::~Client()
{
	if( !isConnected() )
	{
		disconnect();
	}
}

std::vector< sf::Event > Client::requestInput()
{
	return SFMLAdapter::getEvents();
}

void Client::receiveRenderData( std::vector< RenderData > renderData )
{
	render( renderData );
}

void Client::connect( Server* server )
{
	mServer = server;
	mServer->connect( this );
}

void Client::disconnect()
{
	mServer->disconnect( this );
	mServer = nullptr;
}

bool Client::isConnected() const noexcept
{
	return mServer != nullptr;
}

void Client::render( std::vector< RenderData > renderData )
{
	//TODO
}
