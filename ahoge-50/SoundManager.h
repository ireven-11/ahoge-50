#pragma once
#include<string>
#include<unordered_map>

class SoundManager
{
public:
	SoundManager();
	~SoundManager();

	void startSound(const std::string& soundName, const bool isLoop = false, const bool canAllowDuplicate = false);
	void stopSound(const std::string& soundName);

private:
	std::unordered_map<std::string, int> soundHandles_;
};