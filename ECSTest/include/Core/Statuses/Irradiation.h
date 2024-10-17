#pragma once

#include "BaseStatus.h"

class Irraditation : public BaseStatus
{
private:
	void implementation(float deltaSeconds, Actor& target) override;

public:
	Irraditation(std::shared_ptr<Actor> target);

	~Irraditation() = default;
};
