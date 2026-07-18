#pragma once
#include<memory>
#include<vector>

class Player;
class Human;

class ColliderManager
{
public:
	ColliderManager();
	~ColliderManager();

	void init();
	void update(const std::vector<std::shared_ptr<Human>>& humans, const std::shared_ptr<Player>& player);

private:

};