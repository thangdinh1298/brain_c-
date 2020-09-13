#pragma once

#include "Singleton.h"
#include "TrapItem.h"
#include <vector>

class TrapSpawner : public CSingleton<TrapSpawner>
{
public:
	TrapSpawner();
	~TrapSpawner();
	std::vector<std::shared_ptr<TrapItem>> Spawn(float deltaTime);
private:
	float m_currentTime;
};