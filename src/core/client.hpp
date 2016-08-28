#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <vector>
#include <SFML/Window/Event.hpp>
//
#include <nonCopyable.hpp>
#include <ext/SFMLAdapter.hpp>

struct Point;
class Server;
class RenderData;

/*TODO
 *have autonomous thread which renders until next data is received
 *networking stuff( ip etc. )
 */


class Client : SFMLAdapter
{
public:
	Client( const Point& windowSize, const std::string& windowTitle );
	~Client();

	std::vector< sf::Event > requestInput();
	void receiveRenderData( std::vector< RenderData > renderData );

	void connect( Server* server );
	void disconnect();

	bool isConnected() const noexcept;
private:
	void render( std::vector< RenderData > renderData );

	Server* mServer = nullptr;
};

#endif
