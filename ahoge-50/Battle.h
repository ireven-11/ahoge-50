#pragma once
#include"IScene.h"
#include"SceneBase.h"
#include"SceneContext.h"
#include<memory>
#include<vector>

class Player;
class Human;
class ColliderManager;
class Timer;

class Battle : public SceneBase<SceneContext>
{
public:
	Battle(const std::shared_ptr<SceneContext> context);
	~Battle();

	void init();
	void update();
	void draw();
	void enter();
	void exit();
	
private:
	void proceed();
	void gageUI();

	int skydome_;
	std::shared_ptr<Player> player_;
	std::vector<std::shared_ptr<Human>> humans_;
	std::unique_ptr<ColliderManager> collider_;
	std::shared_ptr<Timer> timer_;

	const char human_value = 10;
	const float map_scale = 0.2f;
};