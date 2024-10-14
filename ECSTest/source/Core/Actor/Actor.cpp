#include "Core/Actor/Actor.h"

#include <algorithm>

Actor::Actor(uint64_t life) :
	life(life)
{

}

void Actor::takeDamage(uint64_t damage)
{
	life -= std::min(life, damage);
}
