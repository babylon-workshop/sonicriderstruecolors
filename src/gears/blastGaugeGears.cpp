#include "blastGaugeGears.hpp"
#include "cosmetics/player/exloads.hpp"
#include "riders/gamemode.hpp"
#include "gears/hypersonic.hpp"
#include "macros.h"

std::array<BlastGaugeInfo, MaxPlayerCount> PlayerBlastGaugeInfo;

void Player_BlastGaugeUpdateStatus(Player &player) {
    if (CurrentGameMode != FreeRace &&
        CurrentGameMode != WorldGrandPrix &&
        CurrentGameMode != StoryMode &&
        CurrentGameMode != TimeTrial) { return; }

    switch (player.extremeGear) {
        using namespace ExtremeGear;
        case ChaosEmerald:
            if (player.character == Character::SuperSonic && player.gearExload().exLoadID == EXLoad::HyperSonic) {
                // if hyperdrive has been activated, they are no longer a blast gauge gear
	            HyperSonicInfo *hsInfo = &PlayerHyperSonicInfo[player.index];
                if (hsInfo->hyperdriveEnabled) {
                    player.isBlastGaugeGear = false;
                    break;
                }
            }
            player.isBlastGaugeGear = (player.character == Character::SuperSonic) ||
                                      player.character == Character::Shadow ||
                                      (player.character == Character::Tails && player.superFormState >= 1);
            break;

        case Accelerator:
            player.isBlastGaugeGear = player.gearExload().exLoadID == EXLoad::HyperHangOn;
            break;

        default:
            player.isBlastGaugeGear = false;
            break;
    }
}

ASMUsed s32 Player_BlastGaugeGetAirVal(const Player &player) {
    asm volatile (R"(
        stwu r1, -0x90 (r1)
        stmw r4, 0x8 (r1)
    )");

    const auto val = player.isBlastGaugeGear ? PlayerBlastGaugeInfo[player.index].currentGauge : player.currentAir;

    asm volatile (R"(
        lmw r4, 0x8 (r1)
        addi r1, r1, 0x90
    )");

    return val;
}