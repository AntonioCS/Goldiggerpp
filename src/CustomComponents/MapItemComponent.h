#pragma once

#include "../AcsGE/ECS/Component.h"

class MapItemComponent : public AcsGameEngine::ECS::Component {
public:
	MapItemComponent(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}

	int x;
	int y;
	int w;
	int h;

	bool fill{ false };
};