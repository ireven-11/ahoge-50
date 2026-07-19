#include"DxLib.h"
#include"SoundManager.h"

SoundManager::SoundManager()
{
	soundHandles_["badEndSE"] = LoadSoundMem("sound/badend.mp3");
	soundHandles_["happyEndSE"] = LoadSoundMem("sound/happyend.mp3");
	soundHandles_["bgm"]= LoadSoundMem("sound/bgm.mp3");
	soundHandles_["throwSE"] = LoadSoundMem("sound/throw.mp3");
	soundHandles_["stickSE"] = LoadSoundMem("sound/stick.mp3");
	soundHandles_["giveSE"] = LoadSoundMem("sound/give.mp3");
}

SoundManager::~SoundManager()
{
	for (auto iteretor = soundHandles_.begin(); iteretor != soundHandles_.end(); ++iteretor)
	{
		StopSoundMem(iteretor->second);
	}
	soundHandles_.clear();
	InitSoundMem();
}

void SoundManager::startSound(const std::string& soundName, const bool isLoop, const bool canAllowDuplicate)
{
	//検索した名前がなければ処理をしない
	const auto isExisting = soundHandles_.find(soundName);
	if (isExisting == soundHandles_.end()) return;

	const auto soundHandle = soundHandles_[soundName];

	//重複を許さない場合は音が流れてるかチェックして、流れてたら処理をしない
	if (CheckSoundMem(soundHandle) && !canAllowDuplicate) return;

	if (isLoop)
	{
		PlaySoundMem(soundHandle, DX_PLAYTYPE_LOOP);
	}
	else
	{
		PlaySoundMem(soundHandle, DX_PLAYTYPE_BACK);
	}
}

void SoundManager::stopSound(const std::string& soundName)
{
	//検索した名前がなければ処理をしない
	const auto isExisting = soundHandles_.find(soundName);
	if (isExisting == soundHandles_.end()) return;

	StopSoundMem(soundHandles_[soundName]);
}