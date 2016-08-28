#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <SFML/Window/Event.hpp>
//
#include <entity/entity.hpp>
#include <rendering/renderData.hpp>

class RenderData;

class Player : public Entity
{
public:
	using Entity::Entity;

	std::vector< RenderData > composeRenderData();
	void parseInput( std::vector< sf::Event > events );
};

#endif
