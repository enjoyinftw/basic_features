# game/CMakeLists.txt
add_library(${GAME_TARGET_NAME} STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Game/Game.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Game/Player.cpp
)

set(RESOURCE_FOLDER_NAME "assets")
set(RESOURCE_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${RESOURCE_FOLDER_NAME}")

set(GAMEDATA_FOLDER_NAME "gamedata")
set(GAMEDATA_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${GAMEDATA_FOLDER_NAME}")

configure_file(
	"config.h.in"
	"${CMAKE_CURRENT_SOURCE_DIR}/include/config.h" ESCAPE_QUOTES
)

target_compile_definitions(${GAME_TARGET_NAME} PRIVATE
    RESOURCE_FOLDER_NAME="${RESOURCE_FOLDER_NAME}"
    RESOURCE_SRC_DIR="${RESOURCE_SRC_DIR}"
    GAMEDATA_FOLDER_NAME="${GAMEDATA_FOLDER_NAME}"
    GAMEDATA_SRC_DIR="${GAMEDATA_SRC_DIR}"
)

target_include_directories(${GAME_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


target_compile_features(${GAME_TARGET_NAME} PRIVATE cxx_std_17)
target_link_libraries(${GAME_TARGET_NAME} PUBLIC
    ${ENGINE_TARGET_NAME}
    SFML::Graphics
    SFML::Window
    SFML::System
    SFML::Audio
)
