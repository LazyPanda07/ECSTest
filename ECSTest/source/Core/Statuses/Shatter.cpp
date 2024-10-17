#include "Core/Statuses/Shatter.h"

#include <cmath>

void Shatter::implementation(float deltaSeconds, Actor& target)
{
	target.takeDamage(static_cast<uint64_t>(std::pow(deltaSeconds, 10)));
}

Shatter::Shatter(std::shared_ptr<Actor> target) :
	BaseStatus(6, target)
{

}
