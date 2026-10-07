#pragma once
#include "player_state.h"

namespace twoplayer {

/*
 * Runtime adapter boundary.
 *
 * This is the only layer that should directly call GTA V/PS4-specific
 * functions. Keeping it isolated means the rest of the project can be
 * developed without hard-coding unverified 1.53 addresses.
 */
class GameAdapter {
public:
    bool Initialize();
    void Shutdown();

    bool IsPlayer1Valid() const;

    bool SpawnPedNearPlayer1(PlayerState& player2, float distance);
    void RemovePed(PlayerState& player2);

    void UpdatePlayerMovement(PlayerState& player, float move_x, float move_y);
    void UpdatePlayerLook(PlayerState& player, float look_x, float look_y);

    void GiveWeapon(PlayerState& player, int weapon_id, int ammo);
    void SetHealth(PlayerState& player, float health);

    bool EnterNearestVehicle(PlayerState& player);
    void ExitVehicle(PlayerState& player);

    void SetCameraMode(int player_index, int mode);

private:
    bool initialized_ = false;
};

}
