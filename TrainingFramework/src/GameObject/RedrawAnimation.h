#pragma once

#include "Sprite2D.h"
class RedrawAnimation : public Sprite2D
{
public:
	RedrawAnimation::RedrawAnimation(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture
		, Vector2 startPosVec, float xVelocity, float yVelocity);
	void Update(float deltatime);
protected:
	float m_xVelocity;
	float m_yVelocity;
	Vector2 m_startPos;
	Vector2 m_curPos;
};