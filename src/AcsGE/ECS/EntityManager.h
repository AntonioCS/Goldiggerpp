#pragma once


#include <vector>
#include <memory> //unique_ptr
#include <functional> //std::reference_wrapper
//#include "Entity.h"

namespace AcsGameEngine::ECS {

	class Entity;

	class EntityManager
	{
		std::vector<std::unique_ptr<Entity>> m_entities;
	public:
		EntityManager();
		~EntityManager();

		Entity &make_entity();


		template<typename... Types>
		std::vector<std::reference_wrapper<Entity>> findByComponent() {
			std::vector<std::reference_wrapper<Entity>> ve;
			for (auto &e : m_entities) {
				if (e.get()->hasComponents<Types...>()) {
					ve.push_back(*e);
				}
			}

			return ve;
		}
	};
}
