#pragma once

#include<string>

static std::string GetResourceDir()
{
#ifdef NDEBUG //RELEASE
    return "assets/";
#else
    return "D:/projects/sfml_projects/basic_features/game/assets/";
#endif
}

static std::string GetGameDataDir()
{
#ifdef NDEBUG // RELEASE
    return "gamedata/";
#else
    return "D:/projects/sfml_projects/basic_features/game/gamedata/";
#endif
}
