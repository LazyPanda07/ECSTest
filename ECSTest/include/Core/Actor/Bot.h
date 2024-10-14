#pragma once

#include "Actor.h"

class Bot : public Actor
{
public:
	Bot();

	std::string getName() const override;

	~Bot() = default;
};
