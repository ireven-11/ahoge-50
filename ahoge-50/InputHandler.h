#pragma once
#include<memory>
#include"Singleton.h"

class Mouse;
class KeyInput;

class InputHandler : public Singleton<InputHandler>
{
public:
	~InputHandler();

	void update();
	void init();

	std::shared_ptr<Mouse> getMouse()const noexcept { return mouse_; }
	std::shared_ptr<KeyInput> getKeyInput()const noexcept { return keyInput_; }

private:
	//Singletonのフレンドに宣言してコンストラクタにアクセス許可
	friend class Singleton<InputHandler>;
	InputHandler();

	std::shared_ptr<Mouse>		mouse_;
	std::shared_ptr<KeyInput>	keyInput_;
};