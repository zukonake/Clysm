#include "player.hpp"
#include <iostream>
//
#include <SFML/Window/Event.hpp>
#include <luaPP.hpp>
//
#include <core/dataset.hpp>
#include <outputData.hpp>
#include <inputData.hpp>

Player::Player( const Dataset& dataset, const Point& position, World* world ) :
	Animal( position, world, nullptr ), //TODO change to human
	mSpriteSize( *dataset.getConfig< LPP::Number >( "spriteSize" )),
	mTileSize( *dataset.getConfig< LPP::Number >( "tileSize" ) ),
	mWindowSize( dataset.getConfig< LPP::Table >( "windowSize" )),
	mWindowTitle( *dataset.getConfig< LPP::String>( "windowTitle" ))
{

}

OutputData Player::requestOutputData() noexcept
{
	for( uint16_t iY = 0; iY < mWindowSize.y / mTileSize; iY++ )
	{
		for( uint16_t iX = 0; iX < mWindowSize.x / mTileSize; iX++ )
		{
			//mOutputData.tileMap[{ iX, iY }];
		}
	}
	mOutputData.windowSize = mWindowSize;
	mOutputData.windowTitle = mWindowTitle;
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
