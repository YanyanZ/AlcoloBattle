cmake_minimum_required(VERSION 2.8)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)

project(AlcoloBattle)

set (${PRG_NAME} AlcoloBattle)

# Runtime
include_directories(dll)

# Listing the source files
set(LIBRARY_SOURCES
	implementation/Plugin.cpp
	implementation/ImplementationLibrary.h
	implementation/ImplementationLibrary.cpp
)
set(ACTION_SOURCES
	actions/InterpolateEntityPositionAction.h
	actions/InterpolateEntityPositionAction.cpp
	)

set(SOURCES ${LIBRARY_SOURCES} ${ACTION_SOURCES} CMakeLists.txt)

# Project layout (for visual ide such as Visual Studio)
source_group(cmake FILES CMakeLists.txt)
source_group(sources\\actions FILES ${ACTION_SOURCES})
source_group(sources FILES ${LIBRARY_SOURCES})

# configuring the target
add_library(${PRG_NAME} SHARED ${SOURCES})
target_link_libraries(${PRG_NAME} mlv_allocator)
target_link_libraries(${PRG_NAME} ils)
target_link_libraries(${PRG_NAME} mlv_behavior)
target_link_libraries(${PRG_NAME} mlv_simulation)
target_link_libraries(${PRG_NAME} mlv_simulation)
target_link_libraries(${PRG_NAME} mlv_simulation_components)
target_link_libraries(${PRG_NAME} mlv_simulation_configuration)
target_link_libraries(${PRG_NAME} libprotobuf)
target_link_libraries(${PRG_NAME} pthreads)

# Setting up the output
set_target_properties(${PRG_NAME} PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_LIST_DIR}/..
	RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_LIST_DIR}/..
	DEBUG_POSTFIX _${PLATFORM_STR}-mt-gd
	RELEASE_POSTFIX _${PLATFORM_STR}-mt
	)