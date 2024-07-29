# tmnf-plugins
Proof of concept for creating and using plugins for Trackmania Nations Forever.

## Introduction
This project demonstrates a proof of concept for Trackmania Nations Forever (and possibly United, though it hasn't been tested) that allows users to develop their own plugins for the game without the need to modify the game's original executable.

## How It Works
The game uses `binkw32.dll` as a video player. This is our entry point. We owe a lot to [Thirteen AG Ultimate-ASI-Loader](https://github.com/ThirteenAG/Ultimate-ASI-Loader); without it, this project would not have been possible. You can find more information about the ASI Loader in their repository.

The original `binkw32.dll` in the game's folder is renamed to `binkw32Hooked.dll`, and the 32-bit variant of the Ultimate-ASI-Loader `binkw32.dll` is placed in the game's root directory. This setup allows us to load `.asi` files into the game's memory, enabling modifications to the game's code and behavior. The plugins are essentially `.dll` files that are loaded into the game; I developed them using C++.

## Plugin Examples
I have included some plugin examples along with their source code to help you understand how the plugins work:

- **SkipOutro**: Skips the Trackmania.com video when exiting the game and immediately ends the execution of the game engine, allowing for faster game exits.
- More to come...

## Develop Your Own Plugins
Special thanks and credit go to [pixeltris ModTMNF](https://github.com/pixeltris/ModTMNF) for their work on the game's source files and for making information about the game publicly available. 

I have also included the `TmForever.map` file, which you can use with tools like Ghidra (which I used) to explore the game's internal mechanics and find functions and entry points for modifying the game.

## Project Goals
The goal of this project is to develop an open and easy-to-use plugin system for the game, similar to those found in never Trackmania games. If you are interested in this project, feel free to contribute to creating a more open plugin system that everyone can use and expand upon.
