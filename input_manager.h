#pragma once
#include <cstdint>

namespace twoplayer {

struct ControllerState {
    bool connected = false;
    bool join_pressed = false;
    bool attack = false;
    bool aim = false;
    bool jump = false;
    bool enter_vehicle = false;

    float move_x = 0.0f;
    float move_y = 0.0f;
    float look_x = 0.0f;
    float look_y = 0.0f;
};

class InputManager {
public:
    bool Initialize();
    void Update();

    const ControllerState& GetController(int index) const;

private:
    ControllerState controllers_[4]{};
};

}
