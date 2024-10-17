#include "Core/Statuses/Crit.h"

void Crit::implementation(float deltaSeconds, Actor& target)
{
	if (rand() % 10 > 6)
	{
		target.takeDamage(4);
	}
}

Crit::Crit(std::shared_ptr<Actor> target) :
	BaseStatus(4, target)
{

}
