#include"EffekseerForDXLib/DxLib.h"
#include"Crystal.h"
#include"Player.h"
#include"InputHandler.h"
#include"KeyInput.h"

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
    canFire_ = true;
}

void Player::update()
{
    move();

    if (canFire_)
    {
        crystal_->setPosition(position_);
        changeFireAngle();
        fire();
    }

    crystal_->update();
}

void Player::draw()
{
    crystal_->draw();
}

void Player::move()
{
    if (InputHandler::instance().getKeyInput()->getKeyHoldNow(KEY_INPUT_D, 0))
    {
        ++position_.x;
    }
    else if (InputHandler::instance().getKeyInput()->getKeyHoldNow(KEY_INPUT_A, 0))
    {
        --position_.x;
    }
}

void Player::changeFireAngle()
{
    if (InputHandler::instance().getKeyInput()->getKeyPressedMoment(KEY_INPUT_RIGHT))
    {
        currentFireAngleType_ = static_cast<int>(fireAngle::RIGHT);
        const auto fireDirection = VNorm(VGet(1.0f, 0.0f, 1.0f));
        crystal_->decideMoveVector(fireDirection);
    }
    else if (InputHandler::instance().getKeyInput()->getKeyPressedMoment(KEY_INPUT_LEFT))
    {
        currentFireAngleType_ = static_cast<int>(fireAngle::LEFT);
        const auto fireDirection = VNorm(VGet(-1.0f, 0.0f, 1.0f));
        crystal_->decideMoveVector(fireDirection);
    }
    else if (InputHandler::instance().getKeyInput()->getKeyPressedMoment(KEY_INPUT_UP))
    {
        currentFireAngleType_ = static_cast<int>(fireAngle::STREET);
        const auto fireDirection = VNorm(VGet(0.0f, 0.0f, 1.0f));
        crystal_->decideMoveVector(fireDirection);
    }
}

void Player::fire()
{
   
}