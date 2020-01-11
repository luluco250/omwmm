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
	include/omwmm/extractor.hpp src/omwmm/extractor.cpp
)
target_include_directories(
	libomwmm
	PUBLIC include
	PRIVATE src
	private deps/cpptoml/include
)
target_compile_features(libomwmm PUBLIC cxx_std_17)

add_subdirectory(deps/7zip-cpp ${PROJECT_SOURCE_DIR}/build/build7zpp)
target_include_directories(libomwmm PRIVATE deps/7zip-cpp/Include)
target_link_libraries(libomwmm 7zpp)

add_executable(
	omwmm
	src/cli/main.hpp src/cli/main.cpp
)
target_link_libraries(omwmm PUBLIC libomwmm)
target_include_directories(omwmm PRIVATE src)

set_property(
	DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	PROPERTY VS_STARTUP_PROJECT omwmm
)

if(COMPILER_MSVC)
	add_definitions(-DUNICODE -D_UNICODE)
endif()