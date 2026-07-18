#include"EffekseerForDXLib/DxLib.h"
#include"Crystal.h"

int Crystal::crystalHandle_ = 0;

Crystal::Crystal()
{
    if (crystalHandle_ == 0)
    {
        crystalHandle_ = MV1LoadModel("3dmodel/diamond/diamond.mv1");
    }

    //スタティックのモデルを再利用して読み込み
    modelHandle_ = MV1DuplicateModel(crystalHandle_);

    MV1SetScale(modelHandle_, VGet(model_scale, model_scale, model_scale));

    init();
}

Crystal::~Crystal()
{
    MV1DeleteModel(modelHandle_);
}

void Crystal::init()
{
    position_ = VGet(0.0f, 0.0f, 0.0f);
    moveDirection_ = VGet(0.0f, 0.0f, 0.0f);
    speed_ = 0.0f;
    isMoving_ = false;
}

void Crystal::update()
{
    move();
    rotation();

    MV1SetPosition(modelHandle_, position_);
}

void Crystal::draw()
{
    MV1DrawModel(modelHandle_);

    DrawSphere3D(position_, collider_radius, 8, GetColor(255, 255, 255), GetColor(255, 255, 255), false);
}

void Crystal::decideMoveDirection(const VECTOR direction)
{
    moveDirection_ = direction;
}

void Crystal::setPosition(const VECTOR position)
{
    position_ = position;
    MV1SetPosition(modelHandle_, position_);
}

void Crystal::setFireSpeed(const float fireSpeed)
{
    speed_ = fireSpeed * 0.1f;
}

void Crystal::move()
{
    if (!isMoving_) return;

    speed_ *= deceleration_rate;

    if (speed_ < 0.05f)
    {
        speed_ = 0.0f;
        return;
    }

    position_ = VAdd(position_, VScale(moveDirection_, speed_));
}

void Crystal::startFire()
{
    isMoving_ = true;
}

void Crystal::rotation()
{
    rotationAngle_ += rotation_speed;
    if (rotationAngle_ >= DX_PI_F)
    {
        rotationAngle_ = 0.0f;
    }
    MV1SetRotationXYZ(modelHandle_, VGet(0.0f, rotationAngle_, 0.0f));
}