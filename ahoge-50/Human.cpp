#include"EffekseerForDXLib/DxLib.h"
#include"Human.h"

int Human::humanHandle_ = 0;

Human::Human()
{
	if (humanHandle_ == 0)
	{
		humanHandle_ = MV1LoadModel("3dmodel/human.mv1");
	}

	modelHandle_ = MV1DuplicateModel(humanHandle_);
	const float modelScale = 0.05f;
	MV1SetScale(modelHandle_, VGet(modelScale, modelScale, modelScale));

	init();
}

Human::~Human()
{
	MV1DeleteModel(modelHandle_);
}

void Human::init()
{
	MV1DetachAnim(modelHandle_, attachAnimIndex_);

	isRightMove_ = GetRand(1);
	if (isRightMove_)
	{
		position_.x = -init_position_x;
		MV1SetRotationXYZ(modelHandle_, VGet(0.0f, DX_PI_F * -0.5f, 0.0f));
	}
	else
	{
		position_.x = +init_position_x;
		MV1SetRotationXYZ(modelHandle_, VGet(0.0f, DX_PI_F * 0.5f, 0.0f));
	}
	float spawnPositionZ = static_cast<float>(GetRand(random_position_z));
	position_.z = spawnPositionZ;
	position_.y = 0.0f;
	speed_ = static_cast<float>(GetRand(random_speed) + 1) * 0.1f;
	currentAnimCount_ = 0.0f;
	maxPlayingAnimSpeed_ = 0.0f;

	//最初からアニメーションを流しっぱなしにしたいので初期化でアタッチする
	attachAnimIndex_ = MV1AttachAnim(modelHandle_, 1);
	maxPlayingAnimSpeed_ = MV1GetAttachAnimTotalTime(modelHandle_, attachAnimIndex_);
}

void Human::update()
{
	move();
	anim();
	respawn();

	MV1SetPosition(modelHandle_, position_);
}

void Human::draw()
{
	MV1DrawModel(modelHandle_);

	DrawSphere3D(position_, collider_radius, 8, GetColor(255, 255, 255), GetColor(255, 255, 255), false);
}

void Human::move()
{
	if (isRightMove_)
	{
		position_.x += speed_;
	}
	else
	{
		position_.x -= speed_;
	}
}

void Human::respawn()
{
	if (isRightMove_)
	{
		if (position_.x >= init_position_x)
		{
			init();
		}
	}
	else
	{
		if (position_.x <= -init_position_x)
		{
			init();
		}
	}
}

void Human::anim()
{
	currentAnimCount_ += playing_anim_speed;

	if (currentAnimCount_ >= maxPlayingAnimSpeed_)
	{
		currentAnimCount_ = 0.0f;
	}

	MV1SetAttachAnimTime(modelHandle_, attachAnimIndex_, currentAnimCount_);
}