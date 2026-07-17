#pragma once
#include"IScene.h"
#include"SceneBase.h"
#include"SceneContext.h"

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
};