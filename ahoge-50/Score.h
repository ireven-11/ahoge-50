#pragma once

constexpr int add_score = 100;
constexpr int decrease_score = 500;

class Score
{
public:
	Score();
	~Score();

	void init();
	void add(const int value);
	void decrease(const int value);
	void draw();

	int getCurrentScore()const noexcept { return currentScore_; }

private:
	int currentScore_;
};