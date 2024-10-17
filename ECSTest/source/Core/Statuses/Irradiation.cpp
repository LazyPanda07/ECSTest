#include "Core/Statuses/Irradiation.h"

void Irraditation::implementation(float deltaSeconds, Actor& target)
{
	static float current = 0.0f;

	current += deltaSeconds;

	if (static_cast<int64_t>(current) % 10 > 4)
	{
		target.takeDamage(9);
	}
}

Irraditation::Irraditation(std::shared_ptr<Actor> target) :
	BaseStatus(10, target)
{

}
