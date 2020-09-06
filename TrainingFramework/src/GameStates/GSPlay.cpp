#include "GSPlay.h"

#include "Shaders.h"
#include "Texture.h"
#include "Models.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "../FallingObject.h"
#include "AnimationSprite.h"
#include "Spawner.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSPlay::GSPlay() : m_score(0), m_keyPressed(0)
{
}


GSPlay::~GSPlay()
{

}


void GSPlay::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("background");

	//BackGround
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);

	shader = ResourceManagers::GetInstance()->GetShader("AnimationSpriteShader");

	//Player Object
	FallingObject::Init(); //Init class texture

	m_playerLeftCircle = std::make_shared<FallingObject>(FallingObject::COLOR::YELLOW/*, 0.0f*/);
	m_playerLeftCircle->Set2DPosition(screenWidth / 4, 4.65f * screenHeight / 6);
	m_playerLeftCircle->SetSize(50, 50);

	m_playerRightCircle = std::make_shared<FallingObject>(FallingObject::COLOR::YELLOW/*, 0.0f*/);
	m_playerRightCircle->Set2DPosition(3.0f * screenWidth / 4, 4.65f * screenHeight / 6);
	m_playerRightCircle->SetSize(50, 50);

	//text game title
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd");
	m_scoreText = std::make_shared< Text>(shader, font, "score: 0", TEXT_COLOR::RED, 1.0);
	m_scoreText->Set2DPosition(Vector2(5, 25));


}

void GSPlay::Exit()
{

}


void GSPlay::Pause()
{

}

void GSPlay::Resume()
{

}


void GSPlay::HandleEvents()
{

}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	//InputManager::GetInstance()->RegisterKeyEvent(key, bIsPressed);

	switch (key)
	{
	case 'f':
	case 'F':
		if (bIsPressed) {
			m_keyPressed |= LEFT_SWITCH;
			//std::cout << "Key F pressed\n";
		}
		else {
			m_keyPressed &= ~LEFT_SWITCH;
			//std::cout << "Key F released\n";
		}
		break;
	case 'j':
	case 'J':
		if (bIsPressed) {
			m_keyPressed |= RIGHT_SWITCH;
			//std::cout << "Key J pressed\n";
		}
		else {
			m_keyPressed &= ~RIGHT_SWITCH;
			//std::cout << "Key J released\n";
		}
		break;
	}

	if (m_keyPressed & RIGHT_SWITCH) m_playerRightCircle->ChangeNextColor();
	if (m_keyPressed & LEFT_SWITCH) m_playerLeftCircle->ChangeNextColor();
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
}

void GSPlay::Update(float deltaTime)
{

	m_playerLeftCircle->Update(deltaTime);
	m_playerRightCircle->Update(deltaTime);

	//Update position of each gameObject
	for (auto obj : m_gameObjects) {
		obj->Update(deltaTime);
		//check collision against player object
		if ((m_playerLeftCircle->Overlaps(obj) && m_playerLeftCircle->GetCurrentColor() == obj->GetCurrentColor())
			|| (m_playerRightCircle->Overlaps(obj) && m_playerRightCircle->GetCurrentColor() == obj->GetCurrentColor()))
		{
			//std::cout << "Overlaps\n";
			obj->SetActive(false);
			m_score++;
			m_scoreText->setText(std::to_string(m_score));
		}
	}
	// Remove inactive objects
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		auto obj = m_gameObjects[i];
		if (!obj->isActive()) m_gameObjects.erase(m_gameObjects.begin() + i);
	}

	//Spawn objects if any
	auto ptr = Spawner::GetInstance()->Spawn(deltaTime);
	if (ptr) {
		m_gameObjects.push_back(ptr);
	}
	
	/*if (m_keyPressed & RIGHT_SWITCH) {
		m_playerRightCircle->ChangeNextColor();
		std::cout << "Update\n";
	}
	if (m_keyPressed & LEFT_SWITCH) m_playerLeftCircle->ChangeNextColor();*/
}

void GSPlay::Draw()
{
	m_BackGround->Draw();
	m_scoreText->Draw();
	m_playerLeftCircle->Draw();
	m_playerRightCircle->Draw();
	for (auto obj : m_gameObjects) {
		if(obj->isActive()) obj->Draw();
	}
}

void GSPlay::SetNewPostionForBullet()
{
}