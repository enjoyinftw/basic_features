add_executable(
  ${GAME_TEST_TARGET_NAME}
  ${CMAKE_CURRENT_SOURCE_DIR}/test_game/player_test.cpp
)
target_link_libraries(
  ${GAME_TEST_TARGET_NAME}
  GTest::gtest_main
  ${ENGINE_TARGET_NAME}
  ${GAME_TARGET_NAME}
)

include(GoogleTest)
gtest_discover_tests(${GAME_TEST_TARGET_NAME})