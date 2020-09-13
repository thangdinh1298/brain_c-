#pragma once

#include "AnimationSprite.h"
#include "ResourceManagers.h"
#include <vector>

class ParticleEffect;
class FallingObject : public AnimationSprite
{
public:
	enum COLOR {
		YELLOW = 0,
		PURPLE,
		PINK,
		GREEN,
		NUM_COLOR
	};


	explicit FallingObject(COLOR color, float speed=0.0f);

	~FallingObject();


	static void	Init();

	void		Update(GLfloat deltatime);

	void		ChangeNextColor();

	void		ChangeRandomColor();

	COLOR		GetCurrentColor();

	ParticleEffect GetParticleEffect();

	float		GetCurrentSpeed();

	void		SetCurrentSpeed(float speed);

private:
	COLOR m_currentColor;
	float m_speed;
	static std::shared_ptr<Texture> m_textureVector[4];
	static std::shared_ptr<Shaders> m_shaders;
	static std::shared_ptr<Models> m_model;
};