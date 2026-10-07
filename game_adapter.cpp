#include "game_adapter.h"
#include "debug_log.h"

namespace twoplayer {

bool GameAdapter::Initialize() {
    initialized_ = true;
    Log("GameAdapter initialized");
    return true;
}

void GameAdapter::Shutdown() {
    initialized_ = false;
}

bool GameAdapter::IsPlayer1Valid() const {
    return initialized_;
}

bool GameAdapter::SpawnPedNearPlayer1(PlayerState& player2, float distance) {
    (void)distance;

    // TODO: Implement using verified GTA V CUSA00411 v1.53 game functions.
    // Do not paste offsets from another game version here.
    player2.life = PlayerLifeState::Spawning;
    return false;
}

void GameAdapter::RemovePed(PlayerState& player2) {
    // TODO: remove the actual GTA V entity.
    player2 = PlayerState{};
}

void GameAdapter::UpdatePlayerMovement(
    PlayerState& player, float move_x, float move_y) {
    (void)player;
    (void)move_x;
    (void)move_y;
}

void GameAdapter::UpdatePlayerLook(
    PlayerState& player, float look_x, float look_y) {
    (void)player;
    (void)look_x;
    (void)look_y;
}

void GameAdapter::GiveWeapon(
    PlayerState& player, int weapon_id, int ammo) {
    player.selected_weapon = weapon_id;
    player.ammo = ammo;
}

void GameAdapter::SetHealth(
    PlayerState& player, float health) {
    player.health = health;
}

bool GameAdapter::EnterNearestVehicle(PlayerState& player) {
    (void)player;
    return false;
}

void GameAdapter::ExitVehicle(PlayerState& player) {
    player.in_vehicle = false;
    player.vehicle_handle = 0;
}

void GameAdapter::SetCameraMode(int player_index, int mode) {
    (void)player_index;
    (void)mode;
}

}
