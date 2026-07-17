#pragma once

class Timer
{
public:
	Timer();
	~Timer();

	void init();
	void update();
	void startCountDown(const int startSeconds, const int finishSeconds);
	void startCountUp(const int startSeconds, const int finishSeconds);

	void draw();	//test

	const int	getCurrentSeconds()const noexcept { return currentSeconds_; }
	const int	getPrevSeconds()const noexcept { return prevSeconds_; }
	const bool	hasFinishedCountDown()const noexcept { return isPlayingCountDown_ && finishSecondsCount_ >= currentSeconds_; }
	const bool	hasFinishedCountUp()const noexcept { return isPlayingCountUp_ && finishSecondsCount_ <= currentSeconds_; }

private:
	void countDown();
	void countUp();

	int		frameTime_;
	int		startTime_;
	int		currentSeconds_;
	int 	prevSeconds_;
	int		startSecondsCount_;
	int		finishSecondsCount_;
	bool	isPlayingCountUp_;
	bool	isPlayingCountDown_;
};