#include "../FallingObject.h"
#include "Spawner.h"
#include <stdlib.h>
#include <time.h>

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

Spawner::Spawner() : m_lastSpawnTime(0)
{
	srand(time(NULL));
}

Spawner::~Spawner()
{

}

std::shared_ptr<FallingObject> Spawner::SpawnSingleObject(int currentScore)
{
	FallingObject::COLOR objectColor = static_cast<FallingObject::COLOR>(rand() % FallingObject::COLOR::NUM_COLOR);
	float speed = 100;
	if (currentScore < 5) speed = 100.0f;
	else if (currentScore >= 5 && currentScore < 10) speed = 150.0f;
	else if (currentScore > 10 && currentScore < 20) speed = 200.0f;
	else speed = 250;

	return std::make_shared<FallingObject>(objectColor, speed);
}

std::vector<std::shared_ptr<FallingObject>> Spawner::Spawn(float deltaTime, int currentScore)
{
	static float currentTime = 0.0f;
	static float timeGenerate = 2.5f;

	if (currentScore < 5) timeGenerate = 2.5f;
	else if (currentScore >= 5 && currentScore < 10) timeGenerate = 2.0f;
	else if (currentScore > 10 && currentScore < 20) timeGenerate = 1.75f;
	else timeGenerate = 1.0f;

	std::shared_ptr<FallingObject> ptr = nullptr;
	std::vector<std::shared_ptr<FallingObject>> ptrs;

	currentTime += deltaTime;
	if (currentTime >= timeGenerate) 
	{
		int spawnType = rand() % SPAWN_TYPE::SPAWN_TYPE_COUNT;

		switch (spawnType)
		{
		case SPAWN_TYPE::LEFT:
			ptr = Spawner::GetInstance()->SpawnSingleObject(currentScore);
			ptr->Set2DPosition(screenWidth / 4, 0);
			ptr->SetSize(50, 50);
			ptrs.push_back(ptr);
			break;
		case SPAWN_TYPE::RIGHT:
			ptr = Spawner::GetInstance()->SpawnSingleObject(currentScore);
			ptr->Set2DPosition(3.0f * screenWidth / 4, 0);
			ptr->SetSize(50, 50);
			ptrs.push_back(ptr);
			break;
		case SPAWN_TYPE::BOTH:
			ptr = Spawner::GetInstance()->SpawnSingleObject(currentScore);
			ptr->Set2DPosition(3.0f * screenWidth / 4, 0);
			ptr->SetSize(50, 50);
			ptrs.push_back(ptr);

			ptr = Spawner::GetInstance()->SpawnSingleObject(currentScore);
			ptr->Set2DPosition(screenWidth / 4, 0);
			ptr->SetSize(50, 50);
			ptrs.push_back(ptr);
			break;
		default:
			break;
		}

		currentTime -= timeGenerate;
	}

	return ptrs;
	
}