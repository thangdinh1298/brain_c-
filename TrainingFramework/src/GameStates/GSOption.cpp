#include "GSOption.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSOption::GSOption() : m_time(0.0f), m_switched(false) {

}
 
GSOption::~GSOption() {

}

void GSOption::Init() {
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");

	//background
	auto texture = ResourceManagers::GetInstance()->GetTexture("tutorial_left");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);

}

void GSOption::Exit() {

}

void GSOption::Pause() {

}

void GSOption::Resume() {

}

void GSOption::HandleEvents() {

}

void GSOption::HandleKeyEvents(int key, bool bIsPressed) {

}

void GSOption::HandleTouchEvents(int x, int y, bool bIsPressed) {

}

void GSOption::Update(float deltaTime) {
	m_time += deltaTime;

	if (m_time >= 1.3f)
	{
		if (!m_switched)
		{
			auto texture = ResourceManagers::GetInstance()->GetTexture("tutorial_right");
			auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
			auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
			m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
			m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
			m_BackGround->SetSize(screenWidth, screenHeight);
			m_switched = true;
		}
		else 
		{
			GameStateMachine::GetInstance()->PopState();
		}
		m_time = 0;
	}
}

void GSOption::Draw() {
	m_BackGround->Draw();
}
