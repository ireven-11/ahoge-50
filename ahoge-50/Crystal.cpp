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
}

void Crystal::update()
{
    move();

    MV1SetPosition(modelHandle_, position_);
}

void Crystal::draw()
{
    MV1DrawModel(modelHandle_);
}

void Crystal::decideMoveDirection(const VECTOR direction)
{
    moveDirection_ = direction;
}

void Crystal::setPosition(const VECTOR position)
{
    position_ = position;
}

void Crystal::setFireSpeed(const float fireSpeed)
{
    speed_ = fireSpeed;
}

void Crystal::move()
{
    if (speed_ <= 0.0f) return;

    speed_ -= deceleration_rate;
    VECTOR moveVector = VScale(moveDirection_, speed_);
    VAdd(position_, moveVector);
}