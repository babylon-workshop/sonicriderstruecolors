#pragma once

#include "riders/player.hpp"
#include "riders/gear.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
struct GreedInfo {
	u8 greedTimer;
	u8 greedTimerCap;
	u8 excessTimeCounter;
};
#pragma GCC diagnostic pop

extern std::array<GreedInfo, MaxPlayerCount> PlayerGreedInfo;

void Player_Greed(Player &player);
