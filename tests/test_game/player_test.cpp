#include <gtest/gtest.h>
#include "Game/Player.h"


namespace gp {
    class PlayerTest : public testing::Test {
    protected:
        Player player;
        sf::RenderWindow window{ sf::VideoMode({1920u, 1080u}), "Basic Features" };

        void SetUp() override {
            window.clear();
        };

        void TearDown() override {
            window.close();
        };
    };

    TEST_F(PlayerTest, ConstructorGeneratesPlayer) {
        ASSERT_NO_THROW(Player());
    }

    TEST_F(PlayerTest, RenderFunctionExecutesWithoutError) {
        ASSERT_NO_THROW(player.render(window));
    }
};