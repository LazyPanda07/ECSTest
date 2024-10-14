#include "Core/Statuses/BaseStatus.h"

BaseStatus::BaseStatus(float duration, std::shared_ptr<Actor> target) :
	duration(duration),
	target(target)
{

}

bool BaseStatus::tick(float deltaSeconds)
{
	std::shared_ptr<Actor> actualTarget = target.lock();

	if (!actualTarget)
	{
		return false;
	}

	duration -= deltaSeconds;

	this->implementation(deltaSeconds, *actualTarget);

	return duration > 0.0;
}
