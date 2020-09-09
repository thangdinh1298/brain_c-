#include "ParticleEffect.h"

ParticleEffect::ParticleEffect(float timeToLive) : m_timeToLive(timeToLive)
{

}

void ParticleEffect::AddAnimation(std::shared_ptr<RedrawAnimation> animation_ptr)
{
	animation_ptr->SetSize(16, 16);
	m_animations.push_back(animation_ptr);

}

void ParticleEffect::Draw()
{
	for (auto animation : m_animations)
	{
		animation->Draw();
	}
}

void ParticleEffect::Update(float deltaTime)
{
	if(m_timeToLive > 0) m_timeToLive -= deltaTime;
	for (auto animation : m_animations)
	{
		animation->Update(deltaTime);
	}
}

bool ParticleEffect::IsAlive()
{
	return m_timeToLive > 0;
}