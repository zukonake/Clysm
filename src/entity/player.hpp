#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
//
#include <entity/animal.hpp>
#include <outputData.hpp>

struct InputData;
class Dataset;

class Player : public Animal
{
public:
	Player( const Dataset& dataset, const Point& position, World* world );

	OutputData requestOutputData() noexcept;
	void receiveInputData( InputData inputData ) noexcept;
private:
	OutputData mOutputData;
	uint8_t mSpriteSize;
	uint8_t mTileSize;
	Point mWindowSize;
	std::string mWindowTitle;
};

#endif
