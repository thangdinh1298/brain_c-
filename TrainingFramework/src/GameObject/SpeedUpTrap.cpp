#include "SpeedUpTrap.h"

SpeedUpTrap::SpeedUpTrap(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture)
	: TrapItem(model, shader, texture)
{

}
SpeedUpTrap::~SpeedUpTrap()
{

}

void SpeedUpTrap::Act(std::shared_ptr <FallingObject> fallingObject)
{
	fallingObject->SetCurrentSpeed(fallingObject->GetCurrentSpeed() * 2.0f);
}