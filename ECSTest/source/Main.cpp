#include <iostream>
#include <string>
#include <chrono>
#include <thread>

extern uint64_t runECSTest(size_t seconds);

extern uint64_t runInheritanceTest(size_t seconds);

void printResult(uint64_t ticks, size_t seconds, std::string_view category);

int main(int argc, char** argv) try
{
	using namespace std::chrono_literals;

	size_t seconds = 60;
	uint64_t ecsTicks = runECSTest(seconds);
	
	printResult(ecsTicks, seconds, "ECS");

	std::this_thread::sleep_for(5s);

	uint64_t inheritanceTicks = runInheritanceTest(seconds);

	printResult(inheritanceTicks, seconds, "Inheritance");

	std::cout << static_cast<double>(ecsTicks) / inheritanceTicks << std::endl;

	return 0;
}
catch (const std::exception& e)
{
	std::cerr << e.what() << std::endl;

	exit(2);
}

void printResult(uint64_t ticks, size_t seconds, std::string_view category)
{
	std::cout << category << ": total ticks: " << ticks << ", ticks per seconds: " << static_cast<double>(ticks) / seconds << std::endl;
}
