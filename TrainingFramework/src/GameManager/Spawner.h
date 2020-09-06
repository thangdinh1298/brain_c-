#pragma once

#include "Singleton.h"

class FallingObject;
class Spawner : public CSingleton<Spawner>
{
public:
	Spawner();
	~Spawner();
	std::shared_ptr<FallingObject> SpawnSingleObject();
	std::shared_ptr<FallingObject> Spawn(float deltaTime);

private:
	enum SPAWN_TYPE
	{
		LEFT = 0,
		RIGHT = 1,
		BOTH = 2,
		SPAWN_TYPE_COUNT = 3
	};
	float m_lastSpawnTime;
	
};