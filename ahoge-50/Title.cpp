#include"DxLibForIreven.h"
#include"Title.h"
#include"game.h"
#include"InputHandler.h"
#include"KeyInput.h"
#include"Mouse.h"

Title::Title(const std::shared_ptr<SceneContext>& context)
	:SceneBase(context)
{
}

Title::~Title()
{
}

void Title::init()
{

}

void Title::update()
{

}

void Title::draw()
{
	DrawString(0, 0, "title", GetColor(255, 255, 255));
}

void Title::proceed()
{
	if (!InputHandler::instance().getKeyInput()->getKeyPressedMoment(KEY_INPUT_RETURN)) return;

	Game::instance().proceedToBattle();
}

void Title::enter()
{

}

void Title::exit()
{

}