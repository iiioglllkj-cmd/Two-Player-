#include "two_player.h"
#include "debug_log.h"

static twoplayer::TwoPlayerManager g_manager;

extern "C" void TwoPlayer_Init() {
    twoplayer::Log("TP153 init");
    g_manager.Initialize();
}

extern "C" void TwoPlayer_Tick() {
    g_manager.Tick();
}

extern "C" void TwoPlayer_Shutdown() {
    g_manager.Shutdown();
    twoplayer::Log("TP153 shutdown");
}

// SDK-specific PRX registration/entry-point glue is intentionally isolated.
// It must be filled using the exact GoldHEN/OpenOrbis SDK installed for the
// target environment.
