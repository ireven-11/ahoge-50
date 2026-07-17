#include"DxLibForIreven.h"
#include"FPS.h"
#include"Title.h"
#include"Battle.h"
#include"Game.h"
#include"InputHandler.h"

Game::Game()
	: context_(std::make_shared<SceneContext>()),
	fps_(std::make_unique<FPS>())
{
	titleScene_ = std::make_shared<Title>(context_);
	battleScene_ = std::make_shared<Battle>(context_);

	currentScene_ = titleScene_;
}

Game::~Game()
{
	fps_ = nullptr;
	currentScene_ = nullptr;
	titleScene_ = nullptr;
	battleScene_ = nullptr;
	context_ = nullptr;
}

void Game::update()
{
	while (gameRoopSetting)
	{
		//画面に描かれた物を消す(ゲームループの最初に呼ぶ)
		ClearDrawScreen();

		//入力
		InputHandler::instance().update();

		//シーン
		currentScene_->proceed();
		currentScene_->update();
		currentScene_->draw();

		//fps処理
		fps_->update();
		//fps_->draw();
		fps_->wait();

		//裏画面の内容を表画面に反映(ゲームループの最後に呼ぶ)
		ScreenFlip();
	}
}

void Game::proceedToBattle()
{
	currentScene_->exit();
	currentScene_ = battleScene_;
	currentScene_->enter();
}

void Game::proceedToTitle()
{
	currentScene_->exit();
	currentScene_ = titleScene_;
	currentScene_->enter();
}