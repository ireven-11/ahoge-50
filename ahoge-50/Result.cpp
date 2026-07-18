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
	badEndGraph_ = LoadGraph("graph/badEnd.png");
	happyEndGraph_ = LoadGraph("graph/happyEnd.png");
	backGraph_ = LoadGraph("graph/backGraph.jpg");
}

Result::~Result()
{
	DeleteGraph(badEndGraph_);
	DeleteGraph(happyEndGraph_);
	DeleteGraph(backGraph_);
}

void Result::init()
{

}

void Result::update()
{

}

void Result::draw()
{
	DrawExtendGraph(0, 0, init_screen_width, init_screen_height, backGraph_, true);

	if (context()->getScore()->getCurrentScore() <= 0)
	{
		DrawRotaGraphF(init_screen_width * 0.5f, init_screen_height * 0.5f, 1.0, 0.0, badEndGraph_, true);
	}
	else
	{
		DrawRotaGraphF(init_screen_width * 0.5f, init_screen_height * 0.5f, 1.0, 0.0, happyEndGraph_, true);
	}
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