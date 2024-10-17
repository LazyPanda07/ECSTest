#pragma once

#include "BaseStatus.h"

class Irradiation : public BaseStatus
{
private:
	void implementation(float deltaSeconds, Actor& target) override;

public:
	Irradiation(std::shared_ptr<Actor> target);

	~Irradiation() = default;
};
