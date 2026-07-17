#pragma once
#include"IScene.h"
#include"SceneBase.h"
#include"SceneContext.h"
#include<memory>

class Title : public SceneBase<SceneContext>
{
public:
	Title(const std::shared_ptr<SceneContext>& context);
	~Title();

	void init();
	void update();
	void draw();
	void enter();
	void exit();

private:
	void proceed();
};