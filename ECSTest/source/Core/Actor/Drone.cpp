#include "Core/Actor/Drone.h"

#include <limits>

Drone::Drone() :
	Actor(std::numeric_limits<uint64_t>::max())
{

}

std::string Drone::getName() const
{
	return "Drone";
}
