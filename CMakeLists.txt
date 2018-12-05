cmake_minimum_required(VERSION 3.0)
project(HelloBT)
set(CMAKE_AUTOMOC ON)
find_package(Qt5Core)
find_package(Qt5Bluetooth)
add_executable(${PROJECT_NAME}
	HelloBluetooth.cpp
	Thingy.h
	Thingy.cpp
	Manager.h
	Manager.cpp
	)
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Bluetooth)
