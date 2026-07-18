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
	void beSmile(const VECTOR smilePosition);
	void initSmile();

	const VECTOR	getSpherePosition()const noexcept { return position_; }
	const float		getRadius()const noexcept { return collider_radius; }

private:
	void smileUpdate();
	void move();
	void respawn();
	void anim();

	int smileGraph_;
	char smileCount_;
	VECTOR smilePosition_;
	bool isSmile_;
	VECTOR position_;
	bool isRightMove_;
	float speed_;
	float currentAnimCount_;
	int attachAnimIndex_;
	float maxPlayingAnimSpeed_;
	int modelHandle_;
	static int humanHandle_;

	const float collider_radius = 2.0f;
	const float init_position_x = 50.0f;
	const int	random_position_z = 30;
	const int	random_speed = 5;
	const float playing_anim_speed = 0.2f;
	const char max_smile_count = 50;
	const float rise_smile = 0.25f;
};