#include "TrapItem.h"

TrapItem::TrapItem(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture)
	: Sprite2D(model, shader, texture), m_isActive(true)
{

}

TrapItem::~TrapItem()
{
	
}

bool TrapItem::isActive()
{
	return m_isActive;
}
void TrapItem::setActive(bool state)
{
	m_isActive = state;
}