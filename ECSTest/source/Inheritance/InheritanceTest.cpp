#include <cstdint>
#include <thread>
#include <chrono>
#include <future>

#include "Core/Actor/Bot.h"
#include "Core/Actor/Drone.h"

#include "Core/Statuses/ArcingCurrent.h"
#include "Core/Statuses/Burn.h"
#include "Core/Statuses/Crit.h"
#include "Core/Statuses/Irradiation.h"
#include "Core/Statuses/Shatter.h"
#include "Core/Statuses/Swarm.h"

static uint64_t test(bool& stop);

uint64_t runInheritanceTest(size_t seconds)
{
	bool stop = false;
	std::future<uint64_t> wait = std::async(test, std::ref(stop));

	wait.wait_for(std::chrono::seconds(seconds));

	stop = true;

	return wait.get();
}

uint64_t test(bool& stop)
{
	uint64_t ticks = 0;

	std::vector<std::shared_ptr<Actor>> actors;

	for (size_t i = 0; i < 4; i++)
	{
		actors.emplace_back(std::make_shared<Drone>());
	}

	for (size_t i = 0; i < 16; i++)
	{
		actors.emplace_back(std::make_shared<Bot>());
	}

	for (std::shared_ptr<Actor>& actor : actors)
	{
		actor->addStatus(std::make_shared<ArcingCurrent>(actor));
		actor->addStatus(std::make_shared<ArcingCurrent>(actor));

		actor->addStatus(std::make_shared<Shatter>(actor));
		actor->addStatus(std::make_shared<Shatter>(actor));

		actor->addStatus(std::make_shared<Swarm>(actor));
		actor->addStatus(std::make_shared<Swarm>(actor));

		actor->addStatus(std::make_shared<Irradiation>(actor));
		actor->addStatus(std::make_shared<Irradiation>(actor));

		for (size_t i = 0; i < 4; i++)
		{
			actor->addStatus(std::make_shared<Burn>(actor));
		}

		for (size_t i = 0; i < 7; i++)
		{
			actor->addStatus(std::make_shared<Crit>(actor));
		}
	}

	float deltaSeconds = 0.0;

	while (!stop)
	{
		auto start = std::chrono::high_resolution_clock::now();

		for (std::shared_ptr<Actor>& actor : actors)
		{
			std::vector<std::shared_ptr<BaseStatus>>& statuses = actor->getStatuses();

			for (std::shared_ptr<BaseStatus>& status : statuses)
			{
				status->tick(deltaSeconds);
			}
		}

		auto end = std::chrono::high_resolution_clock::now();
		
		deltaSeconds = static_cast<double>((end - start).count()) / std::chrono::high_resolution_clock::period::den;

		ticks++;
	}

	return ticks;
}
