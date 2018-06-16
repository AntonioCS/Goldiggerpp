#pragma once

namespace AcsGameEngine::ECS {

	class Entity;

	class Component {
	public:
		Entity * parentEntity;

		virtual ~Component() {}
	};

}