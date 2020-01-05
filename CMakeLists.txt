cmake_minimum_required(VERSION 3.16)

project(
	openmw-modmanager
	VERSION 0.1
	DESCRIPTION "Mod manager for OpenMW."
	LANGUAGES CXX
)

add_executable(openmw-modmanager src/main.cpp)