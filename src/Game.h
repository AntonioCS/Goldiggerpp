#pragma once


#include "AcsGE/EventManager.h"
#include "AcsGE/Renderer.h"
#include "AcsGE/Util/ColorList.h"
#include "AcsGE/Window.h"
#include "AcsGE/Texture.h"
//#include "src/Game/EntitySprite.h"
#include "AcsGE/ECS/Entity.h"
#include "AcsGE/ECS/Components/SpriteComponent.h"


namespace {
	constexpr int mapLength = 20;
	constexpr int mapHeight = 10;

	using EntityMap = std::array<std::array<std::unique_ptr<AcsGameEngine::ECS::Entity>, mapLength>, mapHeight>;
}

class Game
{
public:
	Game();
	~Game();
};

