#pragma once

#include "AcsGE/EventManager.h"
#include "AcsGE/Renderer.h"
#include "AcsGE/Util/ColorList.h"
#include "AcsGE/Window.h"
#include "AcsGE/Texture.h"
#include "AcsGE/ECS/EntityManager.h"

namespace {
	constexpr int mapLength = 20;
	constexpr int mapHeight = 10;
}

class Game
{
	std::unordered_map<std::string, std::string> m_imagesPaths{
		{"spritesSheet", "assets/images/Sprites.png" },
		{"background_cave", "assets/images/cave-background.jpg"},
		{"background_cave2", "assets/images/cave-background2.jpg"},
		{"background_snowy", "assets/images/snowy-background.jpg"}
	};

	std::unordered_map<std::string, std::string> m_levelsPaths{
		{ "level1", "assets/levels/level1" },
		{ "level2", "assets/levels/level2" },
		{ "level3", "assets/levels/level3" },
		{ "level4", "assets/levels/level4" }
	};

	std::unordered_map<int, std::string> m_mapMappings{
		{ 1, "block_grass" },
		{ 2, "block" },
		{ 4, "gold" },
		{ 3, "green_ladder" },
		{ 9, "enemy_snake" },
		{ 5, "portal_blue" }
	};
	std::unordered_map<std::string, SDL_Rect> m_spriteMappings{
		{ "block_grass",{ 0, 383, 64, 64 } },
		{ "block",{ 64, 384, 64, 64 } },
		{ "block_snow",{ 128, 383, 64, 64 } },
		{ "gold",{ 192,383,64,64 } },
		{ "green_ladder",{ 256, 384, 64, 64 } },
		{ "spikes",{ 320, 383, 64, 64 } },
		{ "ladder",{ 384, 383, 64, 64 } },
		{ "player",{ 0, 0, 45, 64 } },
		{ "enemy_snake",{ 0, 455, 55, 56 } },
		{ "porta_blue",{ 0, 710, 59, 120 } }
	};

	size_t mapBlocks = 64;
	AcsGameEngine::Renderer &m_renderer;
	AcsGameEngine::ECS::EntityManager &m_em;
	AcsGameEngine::Texture m_spritesTexture{ nullptr };
	const int m_mapLength = 20;
	const int m_mapHeight = 10;

	void generateMap(std::string pathToMap);
	void createEntityType(int value);
public:
	Game(AcsGameEngine::Renderer &renderer, AcsGameEngine::ECS::EntityManager &em);
	~Game();
};

