#ifndef SFMLADAPTER_HPP
#define SFMLADAPTER_HPP

#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
//
#include <nonCopyable.hpp>
#include <geometry/point.hpp>

class SFMLAdapter : NonCopyable
{
public:
	SFMLAdapter( const Point& windowSize, const std::string& windowTitle );

	virtual ~SFMLAdapter();

	void update() noexcept;

	bool isRunning() const noexcept;
	bool isKeyPressed( sf::Keyboard::Key key ) const noexcept;

	std::vector< sf::Event > getEvents() noexcept;
	sf::RenderWindow& getWindow() noexcept;
	Point getWindowSize() const noexcept;
private:
	sf::RenderWindow mWindow;
	sf::Event mEvent;
	sf::Keyboard mKeyboard;
};

#endif
