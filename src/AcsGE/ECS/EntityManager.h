#pragma once


#include <vector>
#include <memory> //unique_ptr

namespace AcsGameEngine::ECS {

	class Entity;

	class EntityManager
	{
		std::vector<std::unique_ptr<Entity>> m_entities;
	public:
		EntityManager();
		~EntityManager();

		Entity &make_entity();
		
		std::vector<Entity&> findByComponent() {

		}
	};
}
