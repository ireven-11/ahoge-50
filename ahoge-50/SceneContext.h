#pragma once
#include<memory>
#include"Camera.h"
#include"Score.h"
#include"SoundManager.h"

//playerなどの色々なシーンで使用するかもしれないオブジェクトを持つクラス
//オブジェクトを呼び出すことはできるが変更はできない
class SceneContext final
{
public:
	SceneContext()
	{
		camera_ = std::make_shared<Camera>();
		score_ = std::make_shared<Score>();
		sound_ = std::make_shared<SoundManager>();
	}
	~SceneContext()
	{
		camera_ = nullptr;
		score_ = nullptr;
		sound_ = nullptr;
	}
	
	const std::shared_ptr<Camera> getCamera()const noexcept { return camera_; }
	const std::shared_ptr<Score> getScore()const noexcept { return score_; }
	const std::shared_ptr<SoundManager> getSoundManager()const noexcept { return sound_; }

private:
	std::shared_ptr<Camera> camera_;
	std::shared_ptr<Score> score_;
	std::shared_ptr<SoundManager> sound_;
};