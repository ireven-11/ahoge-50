#pragma once
#include<memory>

class Crystal;

enum class fireAngle
{
	RIGHT,
	LEFT,
	STREET
};

class Player
{
public:
	Player();
	~Player();

	void init();
	void update();
	void draw();

private:
	void changeFireAngle();
	void chargeFirePower();
	void fire();
	void move();
	void reloadCrystal();

	VECTOR position_;
	int currentFireAngleType_;
	std::shared_ptr<Crystal> crystal_;
	bool canFire_;
	int firePower_;
	bool isCountUpFirePower_;

	const int max_fire_power = 100;
	const int minimum_fire_power = 0;
	const float init_position_z = -20.0f;
};