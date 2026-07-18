#pragma once

class Camera
{
public:
	Camera();
	~Camera();

	void init();
	void update();

private:
	VECTOR position_;
	VECTOR targetPosition_;

	const float init_Y = 30.0f;
	const float init_z = -33.5f;
};