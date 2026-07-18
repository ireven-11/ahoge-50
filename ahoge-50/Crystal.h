#pragma once
#include"ISphereCollider.h"

class Crystal : public ISphereCollider
{
public:
	Crystal();
	~Crystal();

	void init();
	void update();
	void draw();
	void decideMoveDirection(const VECTOR direction);
	void setPosition(const VECTOR position);
	void setFireSpeed(const float fireSpeed);

	const VECTOR getSpherePosition()const noexcept { return position_; }
	const float	getRadius()const noexcept { return collider_radius; }

private:
	void move();

	VECTOR position_;
	VECTOR moveDirection_;
	float speed_;
	int modelHandle_;
	static int crystalHandle_;

	const float model_scale = 1.0f;
	const float collider_radius = 1.0f;
	const float deceleration_rate = 1.0f;
};