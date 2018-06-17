#include "RenderableComponent.h"
namespace AcsGameEngine::ECS {
	bool RenderableComponent::isVisible() const noexcept
	{
		return m_visible;
	}

	void RenderableComponent::setVisiableState(bool state)
	{
		m_visible = state;
	}
}