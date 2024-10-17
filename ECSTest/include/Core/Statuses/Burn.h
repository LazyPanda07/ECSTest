#pragma once

#include "BaseStatus.h"

class Burn : public BaseStatus
{
private:
	float currentPeriod;
	static constexpr float period = 0.5f;

private:
	void implementation(float deltaSeconds, Actor& target) override;

public:
	Burn(std::shared_ptr<Actor> target);

	~Burn() = default;
};
