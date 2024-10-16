#pragma once

#include "BaseStatus.h"

class Shatter : public BaseStatus
{
private:
	void implementation(float deltaSeconds, Actor& target) override;

public:
	Shatter(std::shared_ptr<Actor> target);

	~Shatter() = default;
};
