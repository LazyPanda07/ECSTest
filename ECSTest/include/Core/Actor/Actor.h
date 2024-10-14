#pragma once

#include <string>
#include <cstdint>

class Actor
{
protected:
	uint64_t life;

public:
	Actor() = default;

	Actor(uint64_t life);

	void takeDamage(uint64_t damage);

	virtual std::string getName() const = 0;

	virtual ~Actor() = default;
};
