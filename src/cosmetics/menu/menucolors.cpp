#include "menucolors.hpp"
#include "lib/stdlib.hpp"

constexpr std::array<RGBA32, 1> CustomMenuColors = {{
    {0x00, 0x00, 0x00}	// black
}};

/**
 * Handles setting a custom main menu color.
 *
 * @param graphicalObject The main menu's graphical object.
 * @param object The main menu task's object data.
 */
ASMUsed void RandomizeCustomMenuColors(GraphicalObject *graphicalObject, MainMenuObject1 *object) {
    // originally coded by joe a tron as gecko code, ported to C++
	constexpr auto vanillaColorCount = 6;
	constexpr auto customColorCount = CustomMenuColors.size();
    graphicalObject->tint = CustomMenuColors[0];
}