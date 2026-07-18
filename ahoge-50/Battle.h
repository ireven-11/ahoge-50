#pragma once
#include"IScene.h"
#include"SceneBase.h"
#include"SceneContext.h"
#include<memory>
#include<vector>

class Player;
class Human;

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

	std::shared_ptr<Player> player_;
	std::vector<std::shared_ptr<Human>> humans_;

	const char human_value = 10;
};