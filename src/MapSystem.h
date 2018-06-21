#pragma once

//#include <functional>

#include "AcsGE/Renderer.h"
#include "AcsGE/ECS/EntityManager.h"
#include "AcsGE/ECS/Entity.h"
#include "AcsGE/ECS/Components/SpriteComponent.h"
#include "CustomComponents/MapItemComponent.h"
#include <iostream>

class MapSystem
{
	using Entity = AcsGameEngine::ECS::Entity;
	using EntityManager = AcsGameEngine::ECS::EntityManager;
	using VecEntityRef = std::vector<std::reference_wrapper<Entity>>;
	using Renderer = AcsGameEngine::Renderer;
	using SpriteComponent = AcsGameEngine::ECS::SpriteComponent;

	Renderer &m_renderer;
	EntityManager &m_entityManager;
	VecEntityRef m_vecRef;

public:
	MapSystem(Renderer &renderer, EntityManager &em) :  m_renderer(renderer), m_entityManager(em) {}

	void init() {
		m_vecRef = m_entityManager.findByComponent<MapItemComponent, SpriteComponent>();
	}

	void update(float dt) {

	}

	void render() {
		std::cout << m_vecRef.size() << '\n';
		
		for (const auto ref : m_vecRef) {
			auto &e = ref.get();
			m_renderer.DrawSprite(e.getComponent<SpriteComponent>().getSprite());
		}
	}

	~MapSystem() {}
};