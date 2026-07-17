#include"DxLibForIreven.h"
#include"Mouse.h"
#include"KeyInput.h"
#include"InputHandler.h"
#include<cassert>

InputHandler::InputHandler()
	:mouse_(std::make_shared<Mouse>()),
	keyInput_(std::make_shared<KeyInput>())
{
	init();
}

InputHandler::~InputHandler()
{
	mouse_ = nullptr;
	keyInput_ = nullptr;
}

void InputHandler::init()
{

}

void InputHandler::update()
{
	mouse_->update();
	keyInput_->update();
}