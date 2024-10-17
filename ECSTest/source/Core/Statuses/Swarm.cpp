#include "Core/Statuses/Swarm.h"

void Swarm::implementation(float deltaSeconds, Actor& target)
{
	if (target.getLife() < 500)
	{
		target.takeDamage(target.getLife());
	}
}

Swarm::Swarm(std::shared_ptr<Actor> target) :
	BaseStatus(10, target)
{

}
