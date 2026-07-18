#include"DxLibForIreven.h"
#include"Player.h"
#include"Human.h"
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

void ColliderManager::update(const std::vector<std::shared_ptr<Human>>& humans, const std::shared_ptr<Player>& player)
{
	const auto crystal = player->getCrystal();
	for (const auto& human : humans)
	{
		const bool isHiting = HitCheck_Sphere_Sphere(human->getSpherePosition(), human->getRadius(),
			crystal->getSpherePosition(), crystal->getRadius());

		if (isHiting)
		{
			player->reloadCrystal();
			human->init();
		}
	}
}