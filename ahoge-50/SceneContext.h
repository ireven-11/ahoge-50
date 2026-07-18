#pragma once
#include<memory>
#include"Camera.h"
#include"Score.h"

//playerなどの色々なシーンで使用するかもしれないオブジェクトを持つクラス
//オブジェクトを呼び出すことはできるが変更はできない
class SceneContext final
{
public:
	SceneContext()
	{
		camera_ = std::make_shared<Camera>();
		score_ = std::make_shared<Score>();
	}
	~SceneContext()
	{
		camera_ = nullptr;
		score_ = nullptr;
	}
	
	const std::shared_ptr<Camera> getCamera()const noexcept { return camera_; }
	const std::shared_ptr<Score> getScore()const noexcept { return score_; }

private:
	std::shared_ptr<Camera> camera_;
	std::shared_ptr<Score> score_;
};