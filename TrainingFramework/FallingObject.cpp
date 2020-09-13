#include "FallingObject.h"
#include "ParticleEffect.h"


std::shared_ptr<Texture> FallingObject::m_textureVector[4] = {};
std::shared_ptr<Shaders> FallingObject::m_shaders = nullptr;
std::shared_ptr<Models> FallingObject::m_model = nullptr;

FallingObject::FallingObject(COLOR color, float speed)
	: AnimationSprite (m_model, m_shaders, m_textureVector[color], 0.1f, 6), m_currentColor(color), m_speed(speed)
{

}

FallingObject::~FallingObject()
{

}

//FallingObject::FallingObject(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader/*, std::shared_ptr<Texture> texture*/, float frameTime, int numFrame)
//	: AnimationSprite(model, shader, m_textureVector[COLOR::YELLOW], frameTime, numFrame), m_currentColor(COLOR::YELLOW)
//{
//	
//}

void FallingObject::Init() 
{
	m_model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	m_shaders = ResourceManagers::GetInstance()->GetShader("AnimationSpriteShader");
	m_textureVector[0] = ResourceManagers::GetInstance()->GetTexture("circle_animation_yellow");
	m_textureVector[1] = ResourceManagers::GetInstance()->GetTexture("circle_animation_purple");
	m_textureVector[2] = ResourceManagers::GetInstance()->GetTexture("circle_animation_pink");
	m_textureVector[3] = ResourceManagers::GetInstance()->GetTexture("circle_animation_green");
}

void FallingObject::Update(GLfloat deltaTime)
{
	AnimationSprite::Update(deltaTime);
	auto vec2D = this->Get2DPosition();
	vec2D.y += (deltaTime * this->m_speed);
	this->Set2DPosition(vec2D);
}

void FallingObject::ChangeNextColor() 
{
	m_currentColor = static_cast<COLOR>((static_cast<int> (m_currentColor) + 1));
	if (m_currentColor == COLOR::NUM_COLOR) m_currentColor = YELLOW;
	this->SetTexture(m_textureVector[m_currentColor]);
}

void FallingObject::ChangeRandomColor()
{

}

FallingObject::COLOR FallingObject::GetCurrentColor()
{
	return m_currentColor;
}

ParticleEffect FallingObject::GetParticleEffect()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	ParticleEffect effect(5.0f);
	std::string color = "circle_";
	//return effect;
	switch (m_currentColor)
	{
	case COLOR::YELLOW:
	{
		color += "yellow";
	}
	break;
	case COLOR::PINK:
	{
		color += "pink";
	}
	break;
	case COLOR::PURPLE:
	{
		color += "purple";
	}
	break;
	case COLOR::GREEN:
		color += "green";
	}

	auto texture = ResourceManagers::GetInstance()->GetTexture(color + "_frag1");
	auto ptr = std::make_shared<RedrawAnimation>(model, shader, texture,
		this->Get2DPosition(), 25.0f, -25.0f);
	effect.AddAnimation(ptr);

	texture = ResourceManagers::GetInstance()->GetTexture(color + "_frag2");
	ptr = std::make_shared<RedrawAnimation>(model, shader, texture,
		this->Get2DPosition(), -25.0f, -25.0f);
	effect.AddAnimation(ptr);

	texture = ResourceManagers::GetInstance()->GetTexture(color + "_frag3");
	ptr = std::make_shared<RedrawAnimation>(model, shader, texture,
		this->Get2DPosition(), -25.0f, 25.0f);
	effect.AddAnimation(ptr);

	texture = ResourceManagers::GetInstance()->GetTexture(color + "_frag4");
	ptr = std::make_shared<RedrawAnimation>(model, shader, texture,
		this->Get2DPosition(), 25.0f, 25.0f);

	effect.AddAnimation(ptr);

	return effect;
}

float FallingObject::GetCurrentSpeed()
{
	return m_speed;
}

void FallingObject::SetCurrentSpeed(float speed)
{
	m_speed = speed;
}