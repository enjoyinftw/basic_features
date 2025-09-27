# engine/CMakeLists.txt
add_library(${ENGINE_TARGET_NAME} STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Engine.cpp
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../game/include/config.h
     DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(${ENGINE_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_features(${ENGINE_TARGET_NAME} PUBLIC cxx_std_17)
target_link_libraries(${ENGINE_TARGET_NAME} PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
    SFML::Audio
)

