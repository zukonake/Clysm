#include "renderable.hpp"

Renderable::Renderable( std::istream& in ) noexcept
{
	in.ignore( 255, ' ' );
	in >> mTexturePath;
	loadTexture();
	setupSprite();
}

Renderable::Renderable( const std::string& texturePath ) noexcept :
	mTexturePath( texturePath )
{
	loadTexture();
	setupSprite();
}

void Renderable::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	target.draw( mSprite , states );
	return;
}

void Renderable::loadTexture()
{
	if( !mTexture.loadFromFile( mTexturePath ) )
	{
		throw std::runtime_error( "Renderable::loadTexture, couldn't load texture from file: " + mTexturePath + "." );
		return;
	}
	return;
}

void Renderable::setupSprite() noexcept
{
	mSprite.setTexture( mTexture );
	mSprite.setTextureRect( sf::IntRect( 0, 0, mTexture.getSize().x, mTexture.getSize().y ) );
	return;
}
