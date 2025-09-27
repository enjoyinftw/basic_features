cmake_minimum_required(VERSION 3.28)
project(BasicFeatures LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Custom target names
set(ENGINE_TARGET_NAME Engine)
set(GAME_TARGET_NAME Game)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(
     googletest
     GIT_REPOSITORY https://github.com/google/googletest.git
     GIT_TAG v1.17.0 # Use the latest stable tag
     GIT_SHALLOW ON)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


add_subdirectory(engine)
add_subdirectory(game)
add_subdirectory(tests)
