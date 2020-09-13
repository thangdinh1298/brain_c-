#pragma once
#include "gamestatebase.h"
#include "soloud.h"
#include "soloud_wav.h"

class Sprite2D;
class Sprite3D;
class Text;
class AnimationSprite;
class FallingObject;
class Spawner;
class ParticleEffect;
class Star;
class TrapItem;

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
	std::shared_ptr<Star> m_light1;
	std::shared_ptr<Star> m_light2;
	std::shared_ptr<Star> m_light3;
	std::shared_ptr<AnimationSprite> m_light4;
	std::shared_ptr<Star> m_light5;
	std::shared_ptr<Text>  m_scoreText;
	std::shared_ptr<FallingObject> m_playerLeftCircle;
	std::shared_ptr<FallingObject> m_playerRightCircle;
	std::vector<std::shared_ptr<FallingObject>> m_gameObjects;
	std::vector<std::shared_ptr<Sprite2D>> m_listHeart;
	std::vector<ParticleEffect> m_particleEffects;
	std::vector<std::shared_ptr<TrapItem>> m_listTrap;
	int m_score;
	int m_lives;

	const int LEFT_SWITCH = (1 << 1);
	const int RIGHT_SWITCH = (1 << 2);
	int m_keyPressed;

	SoLoud::Soloud m_soloud;
	SoLoud::Wav m_wav;
};

