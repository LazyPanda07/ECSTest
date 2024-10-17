#pragma once

#include <string>
#include <cstdint>
#include <vector>
#include <memory>

class BaseStatus;

class Actor
{
protected:
	uint64_t life;
	std::vector<std::shared_ptr<BaseStatus>> statuses;

public:
	Actor() = default;

	Actor(uint64_t life);

	void takeDamage(uint64_t damage);

	void addStatus(std::shared_ptr<BaseStatus> status);

	uint64_t getLife() const;

	virtual std::string getName() const = 0;

	std::vector<std::shared_ptr<BaseStatus>>& getStatuses();

	virtual ~Actor() = default;
};
