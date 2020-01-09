cmake_minimum_required(VERSION 3.16)

project(
	openmw-modmanager
	VERSION 0.1
	DESCRIPTION "Mod manager for OpenMW."
	LANGUAGES CXX
)

add_library(
	libomwmm STATIC
	include/omwmm.hpp
	include/omwmm/config.hpp src/omwmm/config.cpp
	include/omwmm/modmanager.hpp src/omwmm/modmanager.cpp
	include/omwmm/exceptions.hpp
)
target_include_directories(
	libomwmm
	PUBLIC include
	PRIVATE src
	private deps/cpptoml/include
)
target_compile_features(libomwmm PUBLIC cxx_std_17)

add_executable(
	omwmm
	src/cli/main.hpp src/cli/main.cpp
)
target_link_libraries(omwmm PUBLIC libomwmm)
target_include_directories(omwmm PRIVATE src)