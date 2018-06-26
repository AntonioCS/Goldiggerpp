#pragma once

#include "../AcsGE/ECS/System.h"
#include "../AcsGE/ECS/EntityManager.h"
#include "../AcsGE/EventManager.h"

class PlayerSystem : public AcsGameEngine::ECS::System
{
	AcsGameEngine::EventManager &m_eventManager;

public:
	PlayerSystem(AcsGameEngine::ECS::EntityManager &em, AcsGameEngine::EventManager &eventManager);
	
	~PlayerSystem();
	
	void init();

	void update(float dt);

	void render();
};

