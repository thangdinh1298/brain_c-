#include "RedrawAnimation.h"
extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

RedrawAnimation::RedrawAnimation(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture
								,Vector2 startPosVec, Vector2 respawnPosVec, float xVelocity, float yVelocity )
	: Sprite2D(model, shader, texture), m_startPos(startPosVec),
	m_xVelocity(xVelocity), m_yVelocity(yVelocity), m_curPos(startPosVec),
	m_respawnPosVec(respawnPosVec)
{
	this->Set2DPosition(startPosVec);
	this->SetSize(50, 50);
}

void RedrawAnimation::Update(float deltatime)
{
	m_curPos.x += m_xVelocity * deltatime;
	m_curPos.y += m_yVelocity * deltatime;
	this->Set2DPosition(m_curPos);
	if (m_curPos.x > screenWidth)
	{
		m_curPos = m_respawnPosVec;
	}
}