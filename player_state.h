#pragma once
#include <cstdint>

namespace twoplayer {

enum class PlayerLifeState {
    Inactive,
    Spawning,
    Alive,
    Dead,
    Despawning
};

struct Vector3 {
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
};

struct PlayerState {
    PlayerLifeState life = PlayerLifeState::Inactive;
    int entity_handle = 0;
    int controller_index = -1;

    Vector3 position{};

    float health = 100.0f;
    float max_health = 100.0f;

    int ammo = 0;
    int selected_weapon = 0;

    bool in_vehicle = false;
    int vehicle_handle = 0;
};

}
