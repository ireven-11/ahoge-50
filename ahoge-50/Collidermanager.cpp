#include"DxLibForIreven.h"
#include"Player.h"
#include"Human.h"
#include"Score.h"
#include"ColliderManager.h"
#include"Crystal.h"
#include"SoundManager.h"

ColliderManager::ColliderManager()
{
}

ColliderManager::~ColliderManager()
{
}


void ColliderManager::init()
{

}

void ColliderManager::update(const std::vector<std::shared_ptr<Human>>& humans, const std::shared_ptr<Player>& player,
	const std::shared_ptr<Score>& score, const std::shared_ptr<SoundManager>& soundManager)
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
			human->beSmile(human->getSpherePosition());
			soundManager->startSound("giveSE", false, true);
		}
		else
		{
			score->decrease(decrease_score);
			soundManager->startSound("stickSE", false, true);
		}

		player->reloadCrystal();
		human->init();
			
		return;
	}
}