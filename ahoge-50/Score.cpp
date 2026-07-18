#include"EffekseerForDXLib/DxLib.h"
#include"Score.h"

Score::Score()
{
	init();
}

Score::~Score()
{
}

void Score::init()
{
	currentScore_ = 0;
}

void Score::add(const int value)
{
	currentScore_ += value;
}

void Score::decrease(const int value)
{
	currentScore_ -= value;
}

void Score::draw()
{
	DrawFormatString(50, 150, GetColor(225, 25, 25), "SCORE:%d", currentScore_);
}