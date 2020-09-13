#pragma once
#include "Sprite2D.h"
#include "../FallingObject.h"

class TrapItem : public Sprite2D
{
public:
	TrapItem(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture);
	~TrapItem();

	virtual void Act(std::shared_ptr <FallingObject> fallingObject) = 0;
	bool isActive();
	void setActive(bool state);

private:
	bool m_isActive;
};