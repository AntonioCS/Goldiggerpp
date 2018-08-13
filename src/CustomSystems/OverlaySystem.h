#pragma once

#include "../AcsGE/ECS/System.h"
#include "../AcsGE/ECS/Entity.h"
#include "../AcsGE/EventManager.h"

class OverlaySystem : public AcsGameEngine::ECS::System
{
	AcsGameEngine::ECS::Entity *m_previousEntity = nullptr;
	AcsGameEngine::EventManager &m_eventManager;

public:
	//using System::System;

	OverlaySystem(AcsGameEngine::ECS::EntityManager &em, AcsGameEngine::EventManager &eventManager) : System(em), m_eventManager(eventManager) {}
	
	void init();

	void update(float dt);

	void render();
};

