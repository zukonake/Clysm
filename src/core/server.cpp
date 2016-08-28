#include "server.hpp"
#include <core/client.hpp>
#include <entity/player.hpp>

Server::~Server()
{
	for( auto& iPair : clients )
	{
		iPair.second->disconnect();
	}
}

void Server::loop()
{
	for( auto& iPair : clients )
	{
		iPair.first.parseInput( iPair.second->requestInput() );
		iPair.second->receiveRenderData( iPair.first.composeRenderData() );
	}
	//TODO simulations
}

void Server::connect( Client* client )
{
	clients.push_back( std::pair< Player, Client* >( Player( { 0, 0 }, nullptr, nullptr ), client ) );
}

void Server::disconnect( Client* client )
{

}
