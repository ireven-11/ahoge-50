#include"EffekseerForDXLib/DxLib.h"
#include"Crystal.h"
#include"Player.h"

Player::Player()
    :crystal_(std::make_shared<Crystal>())
{
}

Player::~Player()
{
    crystal_ = nullptr;
}

void Player::init()
{
    position_ = VGet(0.0f, 0.0f, 0.0f);
    currentFireAngleType_ = static_cast<int>(fireAngle::STREET);
}

void Player::update()
{
    crystal_->update();
}

void Player::draw()
{
    crystal_->draw();
}