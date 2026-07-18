#include"EffekseerForDXLib/DxLib.h"
#include"Human.h"

Human::Human()
{
	init();
}

Human::~Human()
{
}

void Human::init()
{
	isRightMove_ = GetRand(1);
	if (isRightMove_)
	{
		position_.x = -init_position_x;
	}
	else
	{
		position_.x = +init_position_x;
	}
	float spawnPositionZ = static_cast<float>(GetRand(random_position_z));
	position_.z = spawnPositionZ;
	position_.y = 0.0f;
	speed_ = static_cast<float>(GetRand(random_speed) + 1) * 0.1f;
}

void Human::update()
{
	move();
	respawn();
}

void Human::draw()
{
	DrawSphere3D(position_, collider_radius, 8, GetColor(255, 255, 255), GetColor(255, 255, 255), false);
}

void Human::move()
{
	if (isRightMove_)
	{
		position_.x += speed_;
	}
	else
	{
		position_.x -= speed_;
	}
}

void Human::respawn()
{
	if (isRightMove_)
	{
		if (position_.x >= init_position_x)
		{
			init();
		}
	}
	else
	{
		if (position_.x <= -init_position_x)
		{
			init();
		}
	}
}