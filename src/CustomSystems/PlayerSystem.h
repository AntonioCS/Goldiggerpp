#pragma once

#include "../AcsGE/ECS/System.h"
#include "../AcsGE/ECS/EntityManager.h"
#include "../AcsGE/EventManager.h"
#include "../AcsGE/ECS/Entity.h"
#include "../AcsGE/ECS/Component.h"


class PlayerSystem : public AcsGameEngine::ECS::System
{
	AcsGameEngine::EventManager &m_eventManager;

	bool m_leftPressed{ false };
	bool m_rightPressed{ false };
	bool m_upPressed{ false };
	bool m_downPressed{ false };

	AcsGameEngine::ECS::Entity *m_player;

	AcsGameEngine::ECS::Component *m_position = nullptr;
	AcsGameEngine::ECS::Component *m_sprite = nullptr;

public:
	PlayerSystem(AcsGameEngine::ECS::EntityManager &em, AcsGameEngine::EventManager &eventManager);
	
	~PlayerSystem();
	
	void init();

	//void update(std::chrono::milliseconds dt);
	void update(float dt);

	void render();
};

