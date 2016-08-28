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
	explicit Renderable( std::istream& in ) noexcept;
	Renderable( const std::string& texturePath ) noexcept;
	Renderable() = default;
protected:
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const override;
private:
	void loadTexture();
	void setupSprite() noexcept;

	sf::Texture mTexture;
	sf::Sprite mSprite;
	std::string mTexturePath;
};

#endif
