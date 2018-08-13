#pragma once

#include <chrono>

#include "EntityManager.h"
#include "Entity.h"

namespace AcsGameEngine::ECS {
	using VecEntityRef = std::vector<std::reference_wrapper<Entity>>;

	class System {
	protected:
		EntityManager &m_entityManager;
		VecEntityRef m_vecRef;

	public:
		System(EntityManager &em) : m_entityManager(em) {}

		virtual ~System() {}

		virtual void init() = 0;

		//virtual void update(std::chrono::milliseconds deltaTime) = 0;
		virtual void update(float deltaTime) = 0;

		virtual void render() = 0;
	};
}
