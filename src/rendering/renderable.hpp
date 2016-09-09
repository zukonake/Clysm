#ifndef RENDERABLE_HPP
#define RENDERABLE_HPP

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
//
#include <geometry/point.hpp>

class Renderable : public sf::Drawable
{
public:
	Renderable( const std::string& texturePath ) noexcept;
	Renderable() = default;
protected:
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const override;
private:
	void loadTexture( const std::string& texturePath );
	void setupSprite() noexcept;

	sf::Texture mTexture;
	sf::Sprite mSprite;
};

#endif
