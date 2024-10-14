#pragma once

#include <memory>

#include "Core/Actor/Actor.h"

class BaseStatus
{
private:
	float duration;
	std::weak_ptr<Actor> target;

protected:
	virtual void implementation(float deltaSeconds, Actor& target) = 0;

public:
	BaseStatus(float duration, std::shared_ptr<Actor> target);

	virtual bool tick(float deltaSeconds);

	virtual ~BaseStatus() = default;
};
