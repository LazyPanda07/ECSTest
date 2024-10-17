#include "Core/Statuses/Irradiation.h"

void Irradiation::implementation(float deltaSeconds, Actor& target)
{
	static float current = 0.0f;

	current += deltaSeconds;

	if (static_cast<int64_t>(current) % 10 > 4)
	{
		target.takeDamage(9);
	}
}

Irradiation::Irradiation(std::shared_ptr<Actor> target) :
	BaseStatus(10, target)
{

}
