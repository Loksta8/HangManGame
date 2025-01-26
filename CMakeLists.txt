cmake_minimum_required(VERSION 3.10)
project(Hangman)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the wordlist file to the executable as a resource
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Resources/wordlist_dictionary.txt
    ${CMAKE_CURRENT_BINARY_DIR}/wordlist_dictionary.txt COPYONLY)

# Collect all source and header files
file(GLOB_RECURSE SRC_FILES src/*.cpp src/*.hpp)

# Add the executable
add_executable(Hangman ${SRC_FILES})

# Include directories
target_include_directories(Hangman PUBLIC ${PROJECT_SOURCE_DIR}/src)
