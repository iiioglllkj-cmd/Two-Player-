#include "input_manager.h"

namespace twoplayer {

bool InputManager::Initialize() {
    return true;
}

void InputManager::Update() {
    // Runtime-specific controller polling goes here.
    // Controller 0 is Player 1; controller 1 is Player 2.
}

const ControllerState& InputManager::GetController(int index) const {
    static const ControllerState empty{};

    if (index < 0 || index >= 4)
        return empty;

    return controllers_[index];
}

}
