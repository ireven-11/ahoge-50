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
	VECTOR position_;
	int currentFireAngleType_;
	std::shared_ptr<Crystal> crystal_;
};