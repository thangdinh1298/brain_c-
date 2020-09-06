#include "GSOption.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSOption::GSOption() {

}
 
GSOption::~GSOption() {

}

void GSOption::Init() {
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");

	//background
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_main_menu");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);

	//Gameplay button
	texture = ResourceManagers::GetInstance()->GetTexture("button_gameplay_option");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth / 2, 250);
	button->SetSize(200, 50);
	button->SetOnClick([]() {

		});
	m_listButton.push_back(button);

	//Graphics button
	texture = ResourceManagers::GetInstance()->GetTexture("button_graphics_option");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth / 2, 350);
	button->SetSize(200, 50);
	button->SetOnClick([]() {

		});
	m_listButton.push_back(button);
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
	m_BackGround->Update(deltaTime);
	for (auto b : m_listButton) {
		b->Update(deltaTime);
	}
}

void GSOption::Draw() {
	m_BackGround->Draw();
	for (auto b : m_listButton) {
		b->Draw();
	}
}
