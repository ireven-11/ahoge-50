#include"EffekseerForDXLib/DxLib.h"
#include"Player.h"
#include"Battle.h"

Battle::Battle(const std::shared_ptr<SceneContext> context)
	: SceneBase(context),
	player_(std::make_shared<Player>())
{
	init();
}

Battle::~Battle()
{

}


void Battle::init()
{
	player_->init();
}

void Battle::update()
{
	player_->update();
}

void Battle::draw()
{
	DrawString(0, 0, "battle", GetColor(255, 255, 255));

	player_->draw();
}

void Battle::proceed()
{
	
}

void Battle::enter()
{
	
}

void Battle::exit()
{

}