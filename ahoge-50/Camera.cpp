#include"EffekseerForDXLib/DxLib.h"
//#include"EffekseerForDXLib/EffekseerForDXLib.h"
#include"Camera.h"

Camera::Camera()
{
	//ゼットバッファを有効にする
	SetUseZBufferFlag(TRUE);

	// Ｚバッファへの書き込みを有効にする
	SetWriteZBuffer3D(TRUE);

	SetUseSetDrawScreenSettingReset(false);

	SetUseLighting(false);

	init();
}

Camera::~Camera()
{
}

void Camera::init()
{
	position_ = VGet(0.0f, init_Y, init_z);
	targetPosition_ = VGet(0.0f, 0.0f, 0.0f);
}

void Camera::update()
{
	SetCameraNearFar(1.00f, 500.00f);

	//カメラの注視点を設定
	SetCameraPositionAndTarget_UpVecY(position_, targetPosition_);

	// DXライブラリのカメラとEffekseerのカメラを同期する。
	//Effekseer_Sync3DSetting();
}