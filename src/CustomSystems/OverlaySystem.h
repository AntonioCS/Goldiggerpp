#pragma once

#include "../AcsGE/ECS/System.h"
#include "../AcsGE/ECS/Entity.h"

class OverlaySystem : public AcsGameEngine::ECS::System
{
	AcsGameEngine::ECS::Entity *m_previousEntity = nullptr;

public:
	using System::System;

	//OverlaySystem(AcsGameEngine::ECS::EntityManager &em) : System(em) {}
	
	void init();

	void update(float dt);

	void render();
};

