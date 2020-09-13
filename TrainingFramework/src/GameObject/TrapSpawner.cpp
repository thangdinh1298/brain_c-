#include "TrapSpawner.h"
#include "ResourceManagers.h"
#include "TrapItem.h"
#include "SpeedUpTrap.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

TrapSpawner::TrapSpawner() : m_currentTime(0)
{

}
TrapSpawner::~TrapSpawner()
{

}

std::vector<std::shared_ptr<TrapItem>> TrapSpawner::Spawn(float deltaTime)
{
	m_currentTime += deltaTime;
	static float timeGenerate = 3.0f;

	std::vector<std::shared_ptr<TrapItem>> result;
	if (m_currentTime >= timeGenerate)
	{
		auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
		auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
		auto texture = ResourceManagers::GetInstance()->GetTexture("speed_up_trap");

		auto ptr = std::make_shared<SpeedUpTrap>(model, shader, texture);
		ptr->SetSize(50, 50);

		int spawnTypeWidth = rand() % 2;
		float width, height=0;

		//Get width
		switch (spawnTypeWidth)
		{
		case 0: //Spawn left
		{
			width = screenWidth / 4;
		}
		break;
		case 1: //Spawn right
		{
			width = 3.0f * screenWidth / 4;
		}
		break;
		}

		int spawnHeight = rand() % 10;
		height += spawnHeight * (screenHeight/2) / 10;

		ptr->Set2DPosition(width, height);

		result.push_back(ptr);

		m_currentTime -= timeGenerate;
	}

	return result;
}