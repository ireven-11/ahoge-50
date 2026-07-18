#include"DxLibForIreven.h"
#include"Player.h"
#include"Human.h"
#include"Battle.h"
#include"Camera.h"

Battle::Battle(const std::shared_ptr<SceneContext> context)
	: SceneBase(context),
	player_(std::make_shared<Player>())
{
	for (size_t i = 0; i < human_value; i++)
	{
		humans_.emplace_back(std::make_shared<Human>());
	}

	init();
}

Battle::~Battle()
{
	humans_.clear();
}

void Battle::init()
{
	player_->init();
}

void Battle::update()
{
	for (const auto& human : humans_)
	{
		human->update();
	}

	player_->update();

	context()->getCamera()->update();
}

void Battle::draw()
{
	DrawGrid(100.0f, 10.0f, GetColor(25, 25, 225));

	for (const auto& human : humans_)
	{
		human->draw();
	}

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