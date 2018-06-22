#include "Game.h"
#include <sstream> //istringstream
#include <fstream> //ifstream
#include <stdexcept>

#include "AcsGE/ECS/Entity.h"
#include "AcsGE/ECS/Components/RenderableComponent.h"
#include "AcsGE/ECS/Components/SpriteComponent.h"
#include "CustomComponents/MapItemComponent.h"

using Entity = AcsGameEngine::ECS::Entity;
using RenderableComponent = AcsGameEngine::ECS::RenderableComponent;
using SpriteComponent = AcsGameEngine::ECS::SpriteComponent;

void Game::generateMap(std::string pathToMap)
{
	std::ifstream mapFile{ pathToMap };

	if (mapFile.is_open()) {
		std::string line;
		int moveBy = 64;
		int currentMoveByY = 0;

		while (std::getline(mapFile, line))
		{
			int currentMoveByX = 0;
			int mapValue;
			std::istringstream mapLineStream(line);

			while (mapLineStream >> mapValue) {
				if (mapValue != 0) {
					//createEntityType(mapValue);

					auto &e = m_em.make_entity();

					e.addComponent<SpriteComponent>(
						m_spritesTexture,
						m_spriteMappings[m_mapMappings[mapValue]],
						currentMoveByX,
						currentMoveByY
					);
					e.addComponent<RenderableComponent>();
					e.addComponent<MapItemComponent>();
				}
				currentMoveByX += moveBy;
			}

			currentMoveByX = 0;
			currentMoveByY += moveBy;
		}
	}
	else {
		throw std::runtime_error(std::string{ "Unable to open map file: " + pathToMap });
	}
}

void Game::createEntityType(int value) {

}


Game::Game(AcsGameEngine::Renderer &renderer, AcsGameEngine::ECS::EntityManager &em) : m_renderer(renderer), m_em(em)
{
	m_spritesTexture = m_renderer.make_texture(m_imagesPaths["spritesSheet"]);
	generateMap(m_levelsPaths["level1"]);
	//auto backgroundTexture = renderer.make_texture("assets/images/cave-background.jpg");
}

Game::~Game()
{
}
