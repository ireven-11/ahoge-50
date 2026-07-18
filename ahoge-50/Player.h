#pragma once
#include<memory>

constexpr int max_fire_power = 100;

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
	void reloadCrystal();

	const std::shared_ptr<Crystal> getCrystal()const noexcept { return crystal_; }
	const VECTOR getPosition()const noexcept { return position_; }
	const int getFirePower()const noexcept { return firePower_; }

private:
	void changeFireAngle();
	void chargeFirePower();
	void fire();
	void move();

	VECTOR position_;
	int currentFireAngleType_;
	std::shared_ptr<Crystal> crystal_;
	bool canFire_;
	int firePower_;
	bool isCountUpFirePower_;
	int ladyHandle_;

	const int minimum_fire_power = 0;
	const float init_position_z = -20.0f;
	const float adjust_position = 150.0f;
	const float max_position = 12.5f;
	const int charge_power_value = 2;
};