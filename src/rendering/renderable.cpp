#include "renderable.hpp"

Renderable::Renderable( const std::string& texturePath ) noexcept
{
	loadTexture( texturePath );
	setupSprite();
}

void Renderable::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	target.draw( mSprite , states );
}

void Renderable::loadTexture( const std::string& texturePath )
{
	if( !mTexture.loadFromFile( texturePath ) )
	{
		throw std::runtime_error( "Renderable::loadTexture, couldn't load texture from file: " + texturePath + "." );
		return;
	}
}

void Renderable::setupSprite() noexcept
{
	mSprite.setTexture( mTexture );
	mSprite.setTextureRect( sf::IntRect( 0, 0, mTexture.getSize().x, mTexture.getSize().y ) );
}
