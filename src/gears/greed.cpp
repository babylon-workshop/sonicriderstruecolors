#include "greed.hpp"
#include "handlers/player/initgeardata.hpp"
#include "lib/sound.hpp"
#include "cosmetics/player/supersonicaura.hpp"

std::array<GreedInfo, MaxPlayerCount> PlayerGreedInfo;

ASMUsed void Player_GreedPayout(Player* player, s32 payoutAmount) {
    if (player->extremeGear != ExtremeGear::Greed) {return;}

	u32 newRings = (static_cast<u32>(payoutAmount) / 1000) / 3;
    if (newRings > 20) {
        newRings = 20;
    }

    player->rings += newRings;
}

void Player_Greed(Player &player) {
    if (player.extremeGear != ExtremeGear::Greed) {return;}
    GreedInfo *GreedInfo = &PlayerGreedInfo[player.index];

    // Lap levelling
    if ((player.currentLap - 1) > player.level && player.currentLap <= 3) {
        player.level = player.currentLap - 1;
    }

    // Additive Boost Speed based on Rings
    player.gearStats[player.level].boostSpeed = Gears[ExtremeGear::Greed].levelStats[player.level].boostSpeed + pSpeed(static_cast<f32>(player.rings) / 2);

    // Timer cap; EXCESS drain increases as it stays active.
    if (player.rings > 100 && GreedInfo->greedTimerCap > 1) {
        if (GreedInfo->excessTimeCounter == 0) {
            GreedInfo->greedTimerCap -= 1;
        }
    }
    else {
        GreedInfo->greedTimerCap = 10;
    }

    // Greed: EXCESS
    if (player.rings > 100) {
        SuperSonicAuraCXX(player);
        if (GreedInfo->greedTimer == 0 && player.state == PlayerState::Cruise) {
            player.rings -= 1;
        }
    }

    // Timers
    if (GreedInfo->greedTimer == 0) {
        GreedInfo->greedTimer = GreedInfo->greedTimerCap;
    }
    else {
        GreedInfo->greedTimer -= 1;
    }

    if (GreedInfo->excessTimeCounter == 0) {
        GreedInfo->excessTimeCounter = 120;
    }
    else {
        GreedInfo->excessTimeCounter -= 1;
    }
}