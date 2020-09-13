#pragma once
#include "TrapItem.h"

class SpeedUpTrap : public TrapItem
{
public:
	SpeedUpTrap(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture);
	~SpeedUpTrap();

	void Act(std::shared_ptr <FallingObject> fallingObject);
};