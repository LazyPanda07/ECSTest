#include "Core/Actor/Bot.h"

#include <limits>

Bot::Bot() :
	Actor(std::numeric_limits<uint64_t>::max())
{

}

std::string Bot::getName() const
{
	return "Bot";
}
