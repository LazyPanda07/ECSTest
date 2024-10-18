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

#include "ECS/Systems/ArcingCurrentSystem.h"
#include "ECS/Systems/BurnSystem.h"
#include "ECS/Systems/CritSystem.h"
#include "ECS/Systems/IrradiationSystem.h"
#include "ECS/Systems/ShatterSystem.h"
#include "ECS/Systems/SwarmSystem.h"

static uint64_t test(bool& stop);

uint64_t runECSTest(size_t seconds)
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
	std::vector<std::unique_ptr<BaseSystem>> systems;

	systems.reserve(6);

	systems.push_back(std::make_unique<ArcingCurrentSystem>());
	systems.push_back(std::make_unique<ShatterSystem>());
	systems.push_back(std::make_unique<SwarmSystem>());
	systems.push_back(std::make_unique<IrradiationSystem>());
	systems.push_back(std::make_unique<BurnSystem>());
	systems.push_back(std::make_unique<CritSystem>());

	for (size_t i = 0; i < 4; i++)
	{
		actors.emplace_back(std::make_shared<Drone>());
	}

	for (size_t i = 0; i < 20; i++)
	{
		actors.emplace_back(std::make_shared<Bot>());
	}

	for (std::shared_ptr<Actor>& actor : actors)
	{
		dynamic_cast<StatusHolder*>(systems[0].get())->addStatus(ArcingCurrent(actor));
		dynamic_cast<StatusHolder*>(systems[0].get())->addStatus(ArcingCurrent(actor));

		dynamic_cast<StatusHolder*>(systems[1].get())->addStatus(Shatter(actor));
		dynamic_cast<StatusHolder*>(systems[1].get())->addStatus(Shatter(actor));

		dynamic_cast<StatusHolder*>(systems[2].get())->addStatus(Swarm(actor));
		dynamic_cast<StatusHolder*>(systems[2].get())->addStatus(Swarm(actor));

		dynamic_cast<StatusHolder*>(systems[3].get())->addStatus(Irradiation(actor));
		dynamic_cast<StatusHolder*>(systems[3].get())->addStatus(Irradiation(actor));

		for (size_t i = 0; i < 6; i++)
		{
			dynamic_cast<StatusHolder*>(systems[4].get())->addStatus(Burn(actor));
		}

		for (size_t i = 0; i < 12; i++)
		{
			dynamic_cast<StatusHolder*>(systems[5].get())->addStatus(Crit(actor));
		}
	}

	float deltaSeconds = 0.0;

	while (!stop)
	{
		auto start = std::chrono::high_resolution_clock::now();

		for (std::unique_ptr<BaseSystem>& system : systems)
		{
			system->tick(deltaSeconds);
		}

		auto end = std::chrono::high_resolution_clock::now();

		deltaSeconds = static_cast<float>((end - start).count()) / std::chrono::high_resolution_clock::period::den;

		ticks++;
	}

	return ticks;
}
