#pragma once

#include "BaseStatus.h"

class Crit : public BaseStatus
{
private:
	void implementation(float deltaSeconds, Actor& target) override;

public:
	Crit(std::shared_ptr<Actor> target);

	~Crit() = default;
};
