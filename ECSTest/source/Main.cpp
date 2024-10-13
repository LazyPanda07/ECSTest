#include <iostream>
#include <string>

extern uint64_t runECSTest(size_t seconds);

extern uint64_t runInheritanceTest(size_t seconds);

void printResult(uint64_t ticks, size_t seconds, std::string_view category);

int main(int argc, char** argv) try
{
	if (argc != 2)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		std::cerr << "Input number of seconds to test" << std::endl;

		exit(1);
	}

	size_t seconds = std::stoull(argv[1]);
	uint64_t ticks = runECSTest(seconds);

	printResult(ticks, seconds, "ECS");

	ticks = runInheritanceTest(seconds);

	printResult(ticks, seconds, "Inheritance");

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
