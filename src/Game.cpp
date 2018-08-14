#include "Game.h"
#include <sstream> //istringstream
#include <fstream> //ifstream
#include <stdexcept>

#include "AcsGE/ECS/Entity.h"
#include "AcsGE/ECS/Components/RenderableComponent.h"
#include "AcsGE/ECS/Components/SpriteComponent.h"
#include "AcsGE/ECS/Components/PositionComponent.h"
#include "AcsGE/ECS/Components/ColisionComponent.h"
#include "CustomComponents/MapItemComponent.h"
#include "CustomComponents/PlayerComponent.h"



using Entity = AcsGameEngine::ECS::Entity;
using RenderableComponent = AcsGameEngine::ECS::RenderableComponent;
using SpriteComponent = AcsGameEngine::ECS::SpriteComponent;
using PositionComponent = AcsGameEngine::ECS::PositionComponent;
using ColisionComponent = AcsGameEngine::ECS::ColisionComponent;

void Game::generateMap(std::string pathToMap, std::string backgroundImg)
{
	std::ifstream mapFile{ pathToMap };

	if (mapFile.is_open()) {
		auto &bgEntity = m_em.make_entity();

		m_bgTexture = m_renderer.make_texture(m_imagesPaths[backgroundImg]);
		SDL_Rect bgRect{ 0, 0, m_backgroundImageDetails[backgroundImg].first, m_backgroundImageDetails[backgroundImg].second };

		bgEntity.addComponent<SpriteComponent>(
			m_bgTexture,
			bgRect,
			0, 0
		);
		bgEntity.addComponent<RenderableComponent>();

		std::string line;
		int currentMoveByY = 0;

		while (std::getline(mapFile, line))
		{
			int currentMoveByX = 0;
			int mapValue;
			std::istringstream mapLineStream(line);

			while (mapLineStream >> mapValue) {
				auto &e = m_em.make_entity();

				if (mapValue != 0) {
					auto mappings = m_spriteMappings[m_mapMappings[mapValue]];

					e.addComponent<SpriteComponent>(
						m_spritesTexture,
						mappings,
						currentMoveByX,
						currentMoveByY
						);
					e.addComponent<RenderableComponent>();
					e.addComponent<PositionComponent>(currentMoveByX, currentMoveByY);
					e.addComponent<ColisionComponent>(mappings.w, mappings.h);
				}

				e.addComponent<MapItemComponent>(currentMoveByX, currentMoveByY, m_gameValue.blockSize, m_gameValue.blockSize);


				currentMoveByX += m_gameValue.blockSize;
			}

			currentMoveByX = 0;
			currentMoveByY += m_gameValue.blockSize;
		}
	}
	else {
		throw std::runtime_error(std::string{ "Unable to open map file: " + pathToMap });
	}
}

void Game::createEntityType(int value) {

}

Game::Game(AcsGameEngine::Renderer &renderer, AcsGameEngine::ECS::EntityManager &em, GameValues const &gameValue) :
	m_renderer(renderer), m_em(em), m_gameValue(gameValue)
{
	m_spritesTexture = m_renderer.make_texture(m_imagesPaths["spritesSheet"]);


	generateMap(m_levelsPaths["level1"], "background_cave");

	//add player
	auto &e = m_em.make_entity();
	e.addComponent<SpriteComponent>(
		m_spritesTexture,
		m_spriteMappings["player"],
		192,
		512
		);
	e.addComponent<PlayerComponent>();
	e.addComponent<RenderableComponent>();
	e.addComponent<PositionComponent>(192, 512);
}

Game::~Game()
{
}
