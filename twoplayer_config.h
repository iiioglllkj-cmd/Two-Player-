#pragma once

#define TP_TITLE_ID "CUSA00411"
#define TP_GAME_VERSION "1.53"
#define TP_PLUGIN_NAME "TP153.prx"

namespace twoplayer {

enum class CameraMode {
    Shared,
    SplitScreen
};

struct Config {
    bool enabled = true;
    bool require_second_controller = true;
    bool auto_spawn_player2 = true;
    bool allow_player2_weapons = true;
    bool allow_player2_vehicles = true;
    CameraMode camera = CameraMode::Shared;
    float spawn_distance = 3.0f;
};

}
