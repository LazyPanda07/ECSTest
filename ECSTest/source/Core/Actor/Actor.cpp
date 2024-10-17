#include "Core/Actor/Actor.h"

#include <algorithm>

#include "Core/Statuses/BaseStatus.h"

Actor::Actor(uint64_t life) :
	life(life)
{

}

void Actor::takeDamage(uint64_t damage)
{
	life -= std::min(life, damage);
}

void Actor::addStatus(std::shared_ptr<BaseStatus> status)
{
	statuses.emplace_back(status);
}

uint64_t Actor::getLife() const
{
	return life;
}

std::vector<std::shared_ptr<BaseStatus>>& Actor::getStatuses()
{
	return statuses;
}
