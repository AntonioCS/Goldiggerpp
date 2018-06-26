#pragma once

#include "../AcsGE/Renderer.h"
#include "../AcsGE/ECS/EntityManager.h"
#include "../AcsGE/ECS/Entity.h"
#include "../AcsGE/ECS/Components/SpriteComponent.h"
#include "../CustomComponents/MapItemComponent.h"
#include "../AcsGE/ECS/System.h"

class MapSystem : public AcsGameEngine::ECS::System
{
	using Entity = AcsGameEngine::ECS::Entity;
	using EntityManager = AcsGameEngine::ECS::EntityManager;
	using VecEntityRef = std::vector<std::reference_wrapper<Entity>>;
	using Renderer = AcsGameEngine::Renderer;
	using SpriteComponent = AcsGameEngine::ECS::SpriteComponent;

	Renderer &m_renderer;
public:
	MapSystem(EntityManager &em, Renderer &renderer);
	~MapSystem(); 

	void init(); 

	void update(float dt);

	void render();
};