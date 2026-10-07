#pragma once
#include "player_state.h"
#include "input_manager.h"
#include "game_adapter.h"
#include "twoplayer_config.h"

namespace twoplayer {

class TwoPlayerManager {
public:
    bool Initialize();
    void Tick();
    void Shutdown();

    const PlayerState& Player1() const;
    const PlayerState& Player2() const;

private:
    enum class SessionState {
        Waiting,
        Active,
        Stopping
    };

    Config config_{};
    SessionState session_ = SessionState::Waiting;

    PlayerState player1_{};
    PlayerState player2_{};

    InputManager input_{};
    GameAdapter game_{};

    void UpdatePlayer1();
    void UpdatePlayer2();

    void TryJoinPlayer2();
    void StartPlayer2();
    void StopPlayer2();

    void ApplyPlayer2Input();
    void UpdateCamera();
};

}
