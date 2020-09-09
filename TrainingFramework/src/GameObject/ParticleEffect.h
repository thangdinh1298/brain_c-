#pragma once
#include "RedrawAnimation.h"

class ParticleEffect
{
public:
	ParticleEffect(float timeToLive);
	void AddAnimation(std::shared_ptr<RedrawAnimation> animation_ptr);
	void Draw();
	void Update(float deltaTime);
	bool IsAlive();

private:
	std::vector<std::shared_ptr<RedrawAnimation>> m_animations;
	float m_timeToLive;
};