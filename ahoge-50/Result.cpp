#include"DxLibForIreven.h"
#include"Result.h"
#include"game.h"
#include"InputHandler.h"
#include"KeyInput.h"
#include"Mouse.h"
#include"Score.h"

Result::Result(const std::shared_ptr<SceneContext>& context)
	:SceneBase(context)
{
}

Result::~Result()
{
}

void Result::init()
{

}

void Result::update()
{

}

void Result::draw()
{
	DrawString(0, 0, "Result", GetColor(255, 255, 255));
}

void Result::proceed()
{
	if (!InputHandler::instance().getKeyInput()->getKeyPressedMoment(KEY_INPUT_RETURN)) return;

	Game::instance().proceedToTitle();
}

void Result::enter()
{
	context()->getScore()->init();
}

void Result::exit()
{
	context()->getScore()->init();
}