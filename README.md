# SFML Starter

A very simple (Linux-based) starter setup for an [SFML](http://sfml-dev.org/) game with a minimal finite state machine (FSM).

## Use

Clone the repo `git clone https://github.com/kiswa/SFML_Starter`, enter the directory, and run `make`. This will create an executable named `sfml` which you can run to see the demo.

## What's Included

All source files are in the `src` directory.

 * `main.cpp` The main entry point that starts everything going.
 * `game.*pp` The **Game** class contains a **GameData** struct that holds the FSM, Asset Manager, and SFML Window.
 * `asset_manager.*pp` The **AssetManager** class provides long-lived access to `sf::Texture`s and `sf::Font`s.
 * `state_machine.*pp` The **StateMachine** class is just a simple wrapper around a `std::stack` which handles transitioning between states.
 * `state.hpp` The **State** class is an abstract class that each state inherits.
 * `game_state.*pp` The **GameState** class is a *simple* implementation of a game state to show how it might be used.
 * `pause_state.*pp` The **PauseState** class is just to demonstrate changing states without replacing the current state.

