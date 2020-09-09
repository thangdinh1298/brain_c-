#include "Star.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

Star::Star(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture
	, Vector2 startPosVec, Vector2 respawnPosVec, float xVelocity, float yVelocity)
	: RedrawAnimation(model, shader, texture, startPosVec, xVelocity, yVelocity)
{
	m_respawnPosVec = respawnPosVec;
	this->SetSize(50, 50);
}

void Star::Update(float deltatime)
{
	RedrawAnimation::Update(deltatime);
	if (m_curPos.x > screenWidth)
	{
		m_curPos = m_respawnPosVec;
	}
}