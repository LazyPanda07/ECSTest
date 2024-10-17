#include "Core/Statuses/ArcingCurrent.h"

void ArcingCurrent::implementation(float deltaSeconds, Actor& target)
{
	target.takeDamage(1);
}

ArcingCurrent::ArcingCurrent(std::shared_ptr<Actor> target) :
	BaseStatus(5, target)
{

}
