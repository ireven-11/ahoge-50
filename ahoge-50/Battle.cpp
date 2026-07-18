#include"DxLibForIreven.h"
#include"Player.h"
#include"Human.h"
#include"ColliderManager.h"
#include"Timer.h"
#include"Battle.h"
#include"Camera.h"
#include"InputHandler.h"
#include"KeyInput.h"
#include"Game.h"

Battle::Battle(const std::shared_ptr<SceneContext> context)
	: SceneBase(context),
	player_(std::make_shared<Player>()),
	collider_(std::make_unique<ColliderManager>()),
	timer_(std::make_shared<Timer>())
{
	skydome_ = MV1LoadModel("3dmodel/skydome/town.pmx");
	MV1SetScale(skydome_, VGet(map_scale, map_scale, map_scale));
	MV1SetRotationXYZ(skydome_, VGet(0.0f, 0.0f, 0.0f));

	for (size_t i = 0; i < human_value; i++)
	{
		humans_.emplace_back(std::make_shared<Human>());
	}

	init();
}

Battle::~Battle()
{
	MV1DeleteModel(skydome_);
	humans_.clear();
	player_ = nullptr;
	collider_ = nullptr;
	timer_ = nullptr;
}

void Battle::init()
{
	player_->init();
	timer_->init();
	timer_->startCountDown(60, 0);
	for (const auto& human : humans_)
	{
		human->init();
	}
}

void Battle::update()
{
	if (timer_->hasFinishedCountDown())
	{
		proceed();
		return;
	}

	timer_->update();

	for (const auto& human : humans_)
	{
		human->update();
	}

	player_->update();

	collider_->update(humans_, player_, context()->getScore());

	context()->getCamera()->update();

	MV1SetPosition(skydome_, VGet(0.0f, 0.0f, 0.0f));
}

void Battle::draw()
{
	MV1DrawModel(skydome_);

	for (const auto& human : humans_)
	{
		human->draw();
	}

	player_->draw();

	timer_->draw();

	gageUI();

	context()->getScore()->draw();
}

void Battle::proceed()
{
	if (!InputHandler::instance().getKeyInput()->getKeyPressedMoment(KEY_INPUT_RETURN)) return;

	Game::instance().proceedToResult();
}

void Battle::enter()
{
	init();
}

void Battle::exit()
{

}

void Battle::gageUI()
{
	const auto playerPosition = ConvWorldPosToScreenPos(player_->getPosition());
	const int gaugeHeight = 200;

	const float firePowerRate = NormalizeBetween<float>(player_->getFirePower(), 0, max_fire_power);
	DrawBox(playerPosition.x, playerPosition.y, playerPosition.x + 100, playerPosition.y + gaugeHeight, GetColor(225, 25, 25), true);
	DrawBox(playerPosition.x, playerPosition.y + gaugeHeight * (1.0f - firePowerRate), playerPosition.x + 100, playerPosition.y + gaugeHeight, GetColor(25, 225, 25), true);
}