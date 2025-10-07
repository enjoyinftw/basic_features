# gameStart/CMakeLists.txt
add_executable(${GAME_START_TARGET_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)


target_compile_features(${GAME_TARGET_NAME} PRIVATE cxx_std_17)
target_link_libraries(${GAME_START_TARGET_NAME} PRIVATE
    ${GAME_TARGET_NAME}
)
