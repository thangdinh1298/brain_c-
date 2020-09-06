#pragma once

#include "Sprite2D.h"
#include "Texture.h"
#include "Models.h"
#include "Shaders.h"

class AnimationSprite : public Sprite2D 
{
public:
	//AnimationSprite();
	AnimationSprite(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture, float frameTime, int numFrame);

	void				Init() override;
	void				Draw() override;
	virtual void		Update(GLfloat deltatime) override;

private: 
	GLfloat m_currentTime;
	int m_currentFrame;
	GLfloat m_frameTime;
	int m_numFrame;
};