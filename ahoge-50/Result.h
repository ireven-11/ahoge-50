#pragma once
#include"IScene.h"
#include"SceneBase.h"
#include"SceneContext.h"
#include<memory>

class Result : public SceneBase<SceneContext>
{
public:
	Result(const std::shared_ptr<SceneContext>& context);
	~Result();

	void init();
	void update();
	void draw();
	void enter();
	void exit();

private:
	void proceed();

	int badEndGraph_;
	int happyEndGraph_;
	int backGraph_;
};