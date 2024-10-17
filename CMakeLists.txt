cmake_minimum_required(VERSION 3.27.0)

set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR} CACHE STRING "")
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 20)

project(ECSTest)

add_executable(
	${PROJECT_NAME}
	ECSTest/source/Main.cpp
	ECSTest/source/Core/Actor/Actor.cpp
	ECSTest/source/Core/Actor/Bot.cpp
	ECSTest/source/Core/Actor/Drone.cpp
	ECSTest/source/Core/Statuses/ArcingCurrent.cpp
	ECSTest/source/Core/Statuses/BaseStatus.cpp
	ECSTest/source/Core/Statuses/Burn.cpp
	ECSTest/source/Core/Statuses/Crit.cpp
	ECSTest/source/Core/Statuses/Irradiation.cpp
	ECSTest/source/Core/Statuses/Shatter.cpp
	ECSTest/source/Core/Statuses/Swarm.cpp
	ECSTest/source/ECS/ECSTest.cpp
	ECSTest/source/Inheritance/InheritanceTest.cpp
)

target_include_directories(
	${PROJECT_NAME} PUBLIC
	ECSTest/include/
)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
