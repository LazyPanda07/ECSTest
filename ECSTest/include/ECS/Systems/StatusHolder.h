#pragma once

#include "Core/Statuses/BaseStatus.h"

class StatusHolder
{
public:
	virtual void addStatus(BaseStatus&& status) = 0;

	virtual size_t getSize() const = 0;

	virtual ~StatusHolder() = default;
};
