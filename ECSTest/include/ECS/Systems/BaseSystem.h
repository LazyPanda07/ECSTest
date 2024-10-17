#pragma once

class BaseSystem
{
public:
	virtual void tick(float deltaSeconds) = 0;

	virtual ~BaseSystem() = default;
};
