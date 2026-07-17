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
    movePosition_ = VGet(0.0f, 0.0f, 0.0f);
    speed_ = 0.0f;
}

void Crystal::update()
{
    MV1SetPosition(modelHandle_, position_);
}

void Crystal::draw()
{
    MV1DrawModel(modelHandle_);
}

void Crystal::decideMoveVector()
{

}