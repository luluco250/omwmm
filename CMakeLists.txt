cmake_minimum_required(VERSION 3.16)

project(
	openmw-modmanager
	VERSION 0.1
	DESCRIPTION "Mod manager for OpenMW."
	LANGUAGES CXX
)

add_library(
	libomwmm STATIC
	include/omwmm/test.hpp src/omwmm/test.cpp
)
target_include_directories(libomwmm PUBLIC include)
target_compile_features(libomwmm PUBLIC cxx_std_17)

add_executable(omwmm src/main.cpp)
target_link_libraries(omwmm PUBLIC libomwmm)