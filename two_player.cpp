#include "two_player.h"
#include "debug_log.h"

namespace twoplayer {

bool TwoPlayerManager::Initialize() {
    if (!input_.Initialize())
        return false;

    if (!game_.Initialize())
        return false;

    player1_.controller_index = 0;
    player1_.life = PlayerLifeState::Alive;

    session_ = SessionState::Waiting;

    Log("TwoPlayerManager initialized");
    return true;
}

void TwoPlayerManager::Tick() {
    if (session_ == SessionState::Stopping)
        return;

    input_.Update();

    UpdatePlayer1();

    if (session_ == SessionState::Waiting)
        TryJoinPlayer2();

    if (session_ == SessionState::Active)
        UpdatePlayer2();

    UpdateCamera();
}

void TwoPlayerManager::UpdatePlayer1() {
    if (!game_.IsPlayer1Valid())
        player1_.life = PlayerLifeState::Inactive;
}

void TwoPlayerManager::TryJoinPlayer2() {
    const auto& c2 = input_.GetController(1);

    if (!config_.require_second_controller || c2.connected) {
        if (c2.join_pressed || config_.auto_spawn_player2)
            StartPlayer2();
    }
}

void TwoPlayerManager::StartPlayer2() {
    if (player2_.life != PlayerLifeState::Inactive)
        return;

    player2_.controller_index = 1;

    if (game_.SpawnPedNearPlayer1(player2_, config_.spawn_distance)) {
        player2_.life = PlayerLifeState::Alive;
        player2_.health = 100.0f;
        player2_.max_health = 100.0f;

        if (config_.allow_player2_weapons)
            game_.GiveWeapon(player2_, 0, 0);

        session_ = SessionState::Active;
        Log("Player 2 joined");
    }
}

void TwoPlayerManager::UpdatePlayer2() {
    if (player2_.life != PlayerLifeState::Alive)
        return;

    ApplyPlayer2Input();

    if (player2_.health <= 0.0f)
        player2_.life = PlayerLifeState::Dead;
}

void TwoPlayerManager::ApplyPlayer2Input() {
    const auto& c2 = input_.GetController(player2_.controller_index);

    game_.UpdatePlayerMovement(player2_, c2.move_x, c2.move_y);
    game_.UpdatePlayerLook(player2_, c2.look_x, c2.look_y);

    if (c2.enter_vehicle && config_.allow_player2_vehicles)
        game_.EnterNearestVehicle(player2_);
}

void TwoPlayerManager::StopPlayer2() {
    game_.RemovePed(player2_);
    session_ = SessionState::Waiting;
}

void TwoPlayerManager::UpdateCamera() {
    if (config_.camera == CameraMode::Shared)
        game_.SetCameraMode(1, 0);
    else
        game_.SetCameraMode(1, 1);
}

void TwoPlayerManager::Shutdown() {
    StopPlayer2();
    game_.Shutdown();
    session_ = SessionState::Stopping;
}

const PlayerState& TwoPlayerManager::Player1() const {
    return player1_;
}

const PlayerState& TwoPlayerManager::Player2() const {
    return player2_;
}

}
