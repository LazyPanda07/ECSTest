#include "Core/Statuses/Burn.h"

void Burn::implementation(float deltaSeconds, Actor& target)
{
	currentPeriod += deltaSeconds;

	if (currentPeriod >= period)
	{
		currentPeriod -= period;

		target.takeDamage(5);
	}
}

Burn::Burn(std::shared_ptr<Actor> target) :
	BaseStatus(10, target),
	currentPeriod(0.0f)
{

}
