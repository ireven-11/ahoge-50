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
		DrawString(860, 150, "BadEnd", GetColor(25, 25, 225));
		DrawString(200, 225, "強く投げたクリスタルが、通行人に怪我を負わせてしまい逮捕...", GetColor(25, 25, 225));

		DrawRotaGraphF(init_screen_width * 0.5f, init_screen_height * 0.55f, 0.5, 0.0, badEndGraph_, true);
	}
	else
	{
		DrawString(850, 150, "HappyEnd", GetColor(225, 225, 25));
		DrawString(200, 225, "たくさんの人々がクリスタルを受け取り、皆が幸せになった...!!", GetColor(225, 225, 25));

		DrawRotaGraphF(init_screen_width * 0.5f, init_screen_height * 0.55f, 0.5, 0.0, happyEndGraph_, true);
	}

	DrawString(600, UpDownPositionY(900), "press Enter to return title", GetColor(25, 25, 25));

	context()->getScore()->draw();
}

void Result::proceed()
{
	if (!InputHandler::instance().getKeyInput()->getKeyPressedMoment(KEY_INPUT_RETURN)) return;

	Game::instance().proceedToTitle();
}

void Result::enter()
{
	
}

void Result::exit()
{
	context()->getScore()->init();
}