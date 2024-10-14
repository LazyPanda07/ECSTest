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

	if (argc != 2)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		std::cerr << "Input number of seconds to test" << std::endl;

		exit(1);
	}

	size_t seconds = std::stoull(argv[1]);

	printResult(runECSTest(seconds), seconds, "ECS");

	std::this_thread::sleep_for(5s);

	printResult(runInheritanceTest(seconds), seconds, "Inheritance");

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
