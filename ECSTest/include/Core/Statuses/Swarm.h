#pragma once

#include "BaseStatus.h"

class Swarm : public BaseStatus
{
private:
	void implementation(float deltaSeconds, Actor& target) override;

public:
	Swarm(std::shared_ptr<Actor> target);

	~Swarm() = default;
};
