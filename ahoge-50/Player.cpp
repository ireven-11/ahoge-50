#include"EffekseerForDXLib/DxLib.h"
#include"Crystal.h"
#include"SoundManager.h"
#include"Player.h"
#include"InputHandler.h"
#include"KeyInput.h"

Player::Player()
    :crystal_(std::make_shared<Crystal>())
{
    ladyHandle_ = LoadGraph("graph/ozyosama.png");

    init();
}

Player::~Player()
{
    crystal_ = nullptr;
    DeleteGraph(ladyHandle_);
}

void Player::init()
{
    position_ = VGet(0.0f, 0.0f, init_position_z);
    currentFireAngleType_ = static_cast<int>(fireAngle::STREET);
    canFire_ = true;
    firePower_ = 0;
    isCountUpFirePower_ = true;
}

void Player::update(const std::shared_ptr<SoundManager>& soundManager)
{
    move();

    if (canFire_)
    {
        crystal_->setPosition(position_);
        changeFireAngle();
        chargeFirePower();
        fire(soundManager);
    }

    crystal_->update();

    if (!crystal_->getIsMoving()) return;

    if (crystal_->getSpeed() > 0.0f) return;

    reloadCrystal();
}

void Player::draw()
{
    crystal_->draw();

    const auto tempPosition = ConvWorldPosToScreenPos(position_);
    DrawRotaGraphF(tempPosition.x - adjust_position, tempPosition.y + adjust_position, 1.5, 0.0, ladyHandle_, true);
}

void Player::move()
{
    if (InputHandler::instance().getKeyInput()->getKeyHoldNow(KEY_INPUT_D, 0))
    {
        ++position_.x;

        if (position_.x > max_position)
        {
            position_.x = max_position;
        }
    }
    else if (InputHandler::instance().getKeyInput()->getKeyHoldNow(KEY_INPUT_A, 0))
    {
        --position_.x;

        if (position_.x < -max_position)
        {
            position_.x = -max_position;
        }
    }
}

void Player::changeFireAngle()
{
    if (InputHandler::instance().getKeyInput()->getKeyPressedMoment(KEY_INPUT_RIGHT))
    {
        currentFireAngleType_ = static_cast<int>(fireAngle::RIGHT);
    }
    else if (InputHandler::instance().getKeyInput()->getKeyPressedMoment(KEY_INPUT_LEFT))
    {
        currentFireAngleType_ = static_cast<int>(fireAngle::LEFT);
    }
    else if (InputHandler::instance().getKeyInput()->getKeyPressedMoment(KEY_INPUT_UP))
    {
        currentFireAngleType_ = static_cast<int>(fireAngle::STREET);
    }

    if (currentFireAngleType_ == static_cast<int>(fireAngle::RIGHT))
    {
        const auto fireDirection = VNorm(VGet(1.0f, 0.0f, 1.0f));
        crystal_->decideMoveDirection(fireDirection);
    }
    else if (currentFireAngleType_ == static_cast<int>(fireAngle::LEFT))
    {
        const auto fireDirection = VNorm(VGet(-1.0f, 0.0f, 1.0f));
        crystal_->decideMoveDirection(fireDirection);
    }
    else if (currentFireAngleType_ == static_cast<int>(fireAngle::STREET))
    {
        const auto fireDirection = VNorm(VGet(0.0f, 0.0f, 1.0f));
        crystal_->decideMoveDirection(fireDirection);
    }
}

void Player::chargeFirePower()
{
    if (!InputHandler::instance().getKeyInput()->getKeyHoldNow(KEY_INPUT_SPACE, 0)) return;

    if (isCountUpFirePower_)
    {
        firePower_ += charge_power_value;

        if (firePower_ > max_fire_power)
        {
            isCountUpFirePower_ = false;
        }
    }
    else
    {
        firePower_ -= charge_power_value;

        if (firePower_ < minimum_fire_power)
        {
            isCountUpFirePower_ = true;
        }
    }

    crystal_->setFireSpeed(static_cast<float>(firePower_));
}

void Player::fire(const std::shared_ptr<SoundManager>& soundManager)
{
    if (!InputHandler::instance().getKeyInput()->getKeyReleasedMoment(KEY_INPUT_SPACE)) return;

    canFire_ = false;
    crystal_->startFire();
    soundManager->startSound("throwSE", false, true);
}

void Player::reloadCrystal()
{
    crystal_ = std::make_shared<Crystal>();
    crystal_->setPosition(position_);
    canFire_ = true;
    firePower_ = 0;
    isCountUpFirePower_ = true;
}