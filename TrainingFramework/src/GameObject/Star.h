#pragma once

#include "RedrawAnimation.h"

class Star : public RedrawAnimation
{
public:
	Star(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture
		, Vector2 startPosVec, Vector2 respawnPosVec, float xVelocity, float yVelocity);

	void Update(float deltatime);

private:
	Vector2 m_respawnPosVec;
};