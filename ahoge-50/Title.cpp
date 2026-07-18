#include"DxLibForIreven.h"
#include"Title.h"
#include"game.h"
#include"InputHandler.h"
#include"KeyInput.h"
#include"Mouse.h"
#include"Score.h"

Title::Title(const std::shared_ptr<SceneContext>& context)
	:SceneBase(context)
{
	ladyHandle_ = LoadGraph("graph/ozyosamaFront.png");
	crystalHandle_ = MV1LoadModel("3dmodel/diamond/diamond.mv1");
	backGraph_ = LoadGraph("graph/backGraph.jpg");
	logo_ = LoadGraph("graph/logo.png");

	MV1SetScale(crystalHandle_, VGet(crystal_scale, crystal_scale, crystal_scale));

	init();
}

Title::~Title()
{
	DeleteGraph(ladyHandle_);
	MV1DeleteModel(crystalHandle_);
}

void Title::init()
{
	rotationY_ = 0.0f;
	SetFontSize(50);
}

void Title::update()
{
	rotationY_ += rotation_speed;
	if (rotationY_ > DX_PI_F)
	{
		rotationY_ = 0.0f;
	}
	MV1SetRotationXYZ(crystalHandle_, VGet(0.0f, rotationY_, 0.0f));
	MV1SetPosition(crystalHandle_, crystal_position);
}

void Title::draw()
{
	DrawExtendGraph(0, 0, init_screen_width, init_screen_height, backGraph_, true);

	DrawRotaGraph(init_screen_width * 0.5f, init_screen_height * 0.275f, 1.35f, 0.0f, logo_, true);

	DrawRotaGraph(init_screen_width * 0.2f, init_screen_height * 0.75f, 2.0f, 0.0f, ladyHandle_, true);

	MV1DrawModel(crystalHandle_);

	DrawStringF(start_text_position.x, UpDownPositionY(start_text_position.y), "press Enter to Start", GetColor(25, 25, 25));
}

void Title::proceed()
{
	if (!InputHandler::instance().getKeyInput()->getKeyPressedMoment(KEY_INPUT_RETURN)) return;

	Game::instance().proceedToBattle();
}

void Title::enter()
{
	SetFontSize(50);
}

void Title::exit()
{
}