#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include <utility>
#include <vector>
//
#include <nonCopyable.hpp>
#include <entity/player.hpp>

class Client;

//TODO networking stuff( ip etc. )

class Server : NonCopyable
{
public:
	Server() = default;
	~Server();

	void loop();

	void connect( Client* client );
	void disconnect( Client* client );
private:
	std::vector< std::pair< Player, Client* > > clients;
};

#endif
