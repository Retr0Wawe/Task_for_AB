cmake_minimum_required(VERSION 3.12)

project(xml_parser LANGUAGES CXX)

set(CMAKE_CXX_STANDART 17)

set(xml_includes
	src/Core/includes/XMLTree.hpp
)

set(xml_sources
	src/Core/src/XMLTree.cpp
)

add_executable(${PROJECT_NAME}	
	${xml_includes}
	${xml_sources}
	src/main.cpp
)

add_subdirectory(vendor/tinyxml2)

target_link_libraries(${PROJECT_NAME} PRIVATE tinyxml2)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT xml_parser)