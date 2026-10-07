#include "debug_log.h"

// Replace these functions with the logging facility exposed by the selected
// GoldHEN/OpenOrbis SDK when the runtime ABI is finalized.

namespace twoplayer {

void Log(const char*) {}
void LogInt(const char*, int) {}
void LogFloat(const char*, float) {}

}
