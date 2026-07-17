#pragma once

constexpr char mouse_button_buffer_size = 3;	//マウスボタンの総数

struct MouseButtonState
{
	int		frame_;
	int		time_;
	bool	onPressed_;
};

enum MOUSE_BUTTON
{
	LEFT,
	RIGHT,
	MIDDLE
};

class Mouse
{
	//アップデートをInputHandler以外で呼べないようにする
	friend class InputHandler;

public:
	Mouse();
	~Mouse();

	const bool		getButtonPressedMoment(int buttonCode) noexcept;
	const bool		getButtonHoldNow(int buttonCode, float seconds) noexcept;
	const bool		getButtonReleasedMoment(int buttonCode) noexcept;
	const VECTOR	getCursorPosition()const noexcept { return cursorPosition_; }
	const VECTOR	getCursorPosButtonPressedMoment(int buttonCode) noexcept;
	const VECTOR	getCursorPosButtonHoldNow(int buttonCode, float seconds) noexcept;
	const VECTOR	getCursorPosReleasedHoldMoment(int buttonCode) noexcept;

private:
	void update();
	void init();
	void input();
	void changePrevInputState(int buttonCode, bool isPressed);

	VECTOR				cursorPosition_;
	MouseButtonState	buttonState_[mouse_button_buffer_size];
	unsigned int		elapsedTimeCounter_;

	const VECTOR init_cusor_pos = VGet(100.0f, 500.0f, 0.0f);
};