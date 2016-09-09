#include "player.hpp"
#include <SFML/Window/Event.hpp>
#include <iostream>
//
#include <core/dataset.hpp>
#include <outputData.hpp>
#include <inputData.hpp>

Player::Player( const Dataset& dataset, const Point& position, World* world ) :
	Animal( position, world, nullptr ), //TODO change to human
	mSpriteSize( dataset.getConfigField< int >( "spriteSize" )),
	mTileSize( dataset.getConfigField< int >( "tileSize" ) ),
	mScreenSize( dataset.getConfigField< Point >( "screenSize" ))
{
	std::cout << (int) mScreenSize.x;
}

OutputData Player::requestOutputData() noexcept
{
	for( uint16_t iY = 0; iY < mScreenSize.y / mTileSize; iY++ )
	{
		for( uint16_t iX = 0; iX < mScreenSize.x / mTileSize; iX++ )
		{
			//mOutputData.tileMap[{ iX, iY }];
		}
	}
	return mOutputData; //TODO
}

void Player::receiveInputData( InputData inputData ) noexcept
{
	for( auto iEvent : inputData.events )
	{
		if( iEvent.type == sf::Event::Closed )
		{
			mOutputData.end = true;
		}
		if( iEvent.type == sf::Event::KeyPressed ) //TODO remake dis
        {
            switch( iEvent.key.code )
            {
			case sf::Keyboard::Escape:
				mOutputData.end = true;
		        break;
			default:
				break;
            }
        }
	}
}
