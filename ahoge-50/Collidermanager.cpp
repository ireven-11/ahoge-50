#include"DxLibForIreven.h"
#include"Player.h"
#include"Human.h"
#include"Score.h"
#include"ColliderManager.h"
#include"Crystal.h"

ColliderManager::ColliderManager()
{
}

ColliderManager::~ColliderManager()
{
}


void ColliderManager::init()
{

}

void ColliderManager::update(const std::vector<std::shared_ptr<Human>>& humans, const std::shared_ptr<Player>& player, const std::shared_ptr<Score>& score)
{
	const auto crystal = player->getCrystal();
	for (const auto& human : humans)
	{
		const bool isHiting = HitCheck_Sphere_Sphere(human->getSpherePosition(), human->getRadius(),
			crystal->getSpherePosition(), crystal->getRadius());

		if (!isHiting) continue;

 		if (crystal->getSpeed() < strong_speed)
		{
			score->add(add_score);
		}
		else
		{
			score->decrease(decrease_score);
		}

		player->reloadCrystal();
		human->init();
			
		return;
	}
}