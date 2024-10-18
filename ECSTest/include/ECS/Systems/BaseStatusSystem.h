#pragma once

#include "BaseSystem.h"
#include "StatusHolder.h"

#include <vector>

template<typename StatusT>
class BaseStatusSystem :
	public BaseSystem,
	public StatusHolder
{
private:
	std::vector<StatusT> statuses;

public:
	void tick(float deltaSeconds) override;

	void addStatus(BaseStatus&& status) override;

	size_t getSize() const override;
};

template<typename StatusT>
void BaseStatusSystem<StatusT>::tick(float deltaSeconds)
{
	for (StatusT& status : statuses)
	{
		status.tick(deltaSeconds);
	}
}

template<typename StatusT>
void BaseStatusSystem<StatusT>::addStatus(BaseStatus&& status)
{
	statuses.push_back(std::move(dynamic_cast<StatusT&>(status)));
}

template<typename StatusT>
size_t BaseStatusSystem<StatusT>::getSize() const
{
	return statuses.size();
}
