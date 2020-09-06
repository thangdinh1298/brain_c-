#pragma once
#include "gamestatebase.h"

class Sprite2D;
class Sprite3D;
class Text;
class AnimationSprite;
class FallingObject;
class Spawner;

class GSPlay :
	public GameStateBase
{
public:
	GSPlay();
	~GSPlay();

	void Init();
	void Exit();

	void Pause();
	void Resume();

	void HandleEvents();
	void HandleKeyEvents(int key, bool bIsPressed);

	void HandleTouchEvents(int x, int y, bool bIsPressed);
	void Update(float deltaTime);
	void Draw();

	
	void SetNewPostionForBullet();

private:

	std::shared_ptr<Sprite2D> m_BackGround;
	std::shared_ptr<Text>  m_scoreText;
	std::shared_ptr<FallingObject> m_playerLeftCircle;
	std::shared_ptr<FallingObject> m_playerRightCircle;
	std::vector<std::shared_ptr<FallingObject>> m_gameObjects;
	int m_score;

	const int LEFT_SWITCH = (1 << 1);
	const int RIGHT_SWITCH = (1 << 2);
	int m_keyPressed;
};

