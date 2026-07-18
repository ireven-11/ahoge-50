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

	int ladyHandle_;
	int crystalHandle_;
	float rotationY_;
	int backGraph_;
	int logo_;

	const float crystal_scale = 20.0f;
	const VECTOR crystal_position = VGet(200.0f, 625.0f, 0.0f);
	const float rotation_speed = 0.02f;
	const VECTOR start_text_position = VGet(675.0, 700.0f, 0.0f);
};