cmake_minimum_required (VERSION 3.22.1 FATAL_ERROR)

project(RegisterCard)

set(CMAKE_CXX_STANDARD 17)

add_executable (RegisterCardApp src/main.cpp
				src/regcard.cpp
				headers/regcard.hpp)
