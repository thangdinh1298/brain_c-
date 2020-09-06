#include "../FallingObject.h"
#include "Spawner.h"
#include <stdlib.h>
#include <time.h>

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

Spawner::Spawner() : m_lastSpawnTime(0)
{

}

Spawner::~Spawner()
{

}

std::shared_ptr<FallingObject> Spawner::SpawnSingleObject()
{
	srand(time(NULL));
	FallingObject::COLOR objectColor = static_cast<FallingObject::COLOR>(rand() % FallingObject::COLOR::NUM_COLOR);
	return std::make_shared<FallingObject>(objectColor, 100.0f);
}

std::shared_ptr<FallingObject> Spawner::Spawn(float deltaTime)
{
	static float currentTime = 0.0f;
	const static float timeGenerate = 3.0f;

	std::shared_ptr<FallingObject> ptr = nullptr;

	currentTime += deltaTime;
	if (currentTime >= timeGenerate) 
	{
		srand(time(NULL));
		int spawnType = rand() % SPAWN_TYPE::SPAWN_TYPE_COUNT;

		switch (spawnType)
		{
		case SPAWN_TYPE::LEFT:
			ptr = Spawner::GetInstance()->SpawnSingleObject();
			ptr->Set2DPosition(screenWidth / 4, 0);
			break;
		case SPAWN_TYPE::RIGHT:
			ptr = Spawner::GetInstance()->SpawnSingleObject();
			ptr->Set2DPosition(3.0f * screenWidth / 4, 0);
			break;
		case SPAWN_TYPE::BOTH:
			ptr = Spawner::GetInstance()->SpawnSingleObject();
			ptr->Set2DPosition(3.0f * screenWidth / 4, 0);
			break;
		default:
			break;
		}
		if (ptr) {
			ptr->SetSize(50, 50);
		}

		currentTime -= timeGenerate;
	}

	return ptr;
	
}