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
	void startFire();

	const VECTOR getSpherePosition()const noexcept { return position_; }
	const float	getRadius()const noexcept { return collider_radius; }
	const bool getIsMoving()const noexcept { return isMoving_; }
	const bool getSpeed()const noexcept { return speed_; }

private:
	void move();
	void rotation();

	VECTOR position_;
	VECTOR moveDirection_;
	float speed_;
	bool isMoving_;
	int modelHandle_;
	float rotationAngle_;
	static int crystalHandle_;

	const float model_scale = 0.5f;
	const float collider_radius = 1.0f;
	const float deceleration_rate = 1.0f;
	const float rotation_speed = 0.5f;
};