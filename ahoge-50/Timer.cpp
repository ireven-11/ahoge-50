#include"EffekseerForDXLib/DxLib.h"
#include"Timer.h"

Timer::Timer()
{
	init();
}

Timer::~Timer()
{
}

void Timer::init()
{
	frameTime_ = 0;
	currentSeconds_ = 0;
	prevSeconds_ = 0;
	startTime_ = 0;
	finishSecondsCount_ = 0;
	isPlayingCountUp_ = false;
	isPlayingCountDown_ = false;
}

void Timer::update()
{
	if (isPlayingCountDown_)
	{
		countDown();

		return;
	}

	if (isPlayingCountUp_)
	{
		countUp();

		return;
	}
}

void Timer::draw()
{
	DrawFormatString(0, 50, GetColor(255, 25, 25), "クリアまで：%d", currentSeconds_);	//てすと
}

void Timer::startCountDown(const int startSecondsCount, const int finishSecondsCount)
{
	//開始する時間が終了する時間より小さいとバグるので処理しない
	if (startSecondsCount < finishSecondsCount) return;

	isPlayingCountDown_ = true;
	startTime_ = GetNowCount();
	startSecondsCount_ = startSecondsCount;
	finishSecondsCount_ = finishSecondsCount;
	currentSeconds_ = startSecondsCount;
	prevSeconds_ = currentSeconds_;
}

void Timer::startCountUp(const int startSecondsCount, const int finishSecondsCount)
{
	//開始する時間が終了する時間より大きいとバグるので処理しない
	if (startSecondsCount > finishSecondsCount) return;

	isPlayingCountUp_ = true;
	startTime_ = GetNowCount();
	startSecondsCount_ = startSecondsCount;
	finishSecondsCount_ = finishSecondsCount;
	currentSeconds_ = startSecondsCount;
	prevSeconds_ = currentSeconds_;
}

void Timer::countDown()
{
	frameTime_ = GetNowCount() - startTime_;
	prevSeconds_ = currentSeconds_;
	currentSeconds_ = startSecondsCount_ - frameTime_ * 0.001f;
}

void Timer::countUp()
{
	frameTime_ = GetNowCount() - startTime_;
	prevSeconds_ = currentSeconds_;
	currentSeconds_ = startSecondsCount_ + frameTime_ * 0.001f;
}