# GTA V Two Player — CUSA00411 v1.53 — Dev 2

This version expands the project architecture for a local two-player mode.

Implemented at architecture level:
- Player 1 / Player 2 state
- Independent health/ammo
- Player 2 lifecycle
- Input abstraction
- Spawn/despawn requests
- Vehicle state abstraction
- Camera mode abstraction
- Configuration
- Debug logging interface

Still requires runtime-specific GTA V 1.53 native/game interfaces and the
GoldHEN/OpenOrbis plugin ABI to become a functional in-game PRX.

No GTA V game files are included.
