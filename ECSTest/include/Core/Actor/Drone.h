#pragma once

#include "Actor.h"

class Drone : public Actor
{
public:
	Drone();

	std::string getName() const override;

	~Drone() = default;
};
