#pragma once
#include"ISphereCollider.h"

class Human: public ISphereCollider
{
public:
	Human();
	~Human();

	void init();
	void update();
	void draw();

	const VECTOR	getSpherePosition()const noexcept { return position_; }
	const float		getRadius()const noexcept { return collider_radius; }

private:
	void move();
	void respawn();

	VECTOR position_;
	bool isRightMove_;
	int modelHandle_;
	int humanHandle_;
	float speed_;

	const float collider_radius = 1.0f;
	const float init_position_x = 50.0f;
	const int	random_position_z = 20;
	const int	random_speed = 5;
};