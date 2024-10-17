#pragma once

#include "BaseStatus.h"

class ArcingCurrent : public BaseStatus
{
private:
	void implementation(float deltaSeconds, Actor& target) override;

public:
	ArcingCurrent(std::shared_ptr<Actor> target);
	
	~ArcingCurrent() = default;
};
