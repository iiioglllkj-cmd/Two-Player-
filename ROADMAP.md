# Development roadmap

## Done in Dev 2
- Project architecture separated into runtime adapter and gameplay logic.
- Player lifecycle.
- Controller abstraction.
- Health/ammo state.
- Vehicle state.
- Camera abstraction.
- Configuration.
- Debug logging interface.

## Next
1. Connect the plugin ABI.
2. Connect controller input.
3. Connect verified GTA V 1.53 entity functions.
4. Spawn Player 2.
5. Implement movement.
6. Implement weapons.
7. Implement vehicle handling.
8. Implement camera.
9. Add HUD and player indicators.
10. Stress-test spawn/death/vehicle transitions.

## Rule
No memory address/offset should be assumed valid for CUSA00411 v1.53
unless verified against that exact executable.
