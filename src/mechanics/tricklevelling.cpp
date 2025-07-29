#include "tricklevelling.hpp"
#include "lib/sound.hpp"
#include "riders/object.hpp"

std::array<TrickLevelInfo, MaxPlayerCount> PlayerTrickLevelInfo;

void Player_CreateTrickLevelUpParticles(Player &player) {
    auto &particles = *static_cast<ParticleTaskObject1 *>(SetTask(func_Particle_Task, ObjectGroups::Particle, Object1Sizes::x80)->object);
	particles.unk72 = player.index;
	particles.x = 0.0F;
	particles.z = 0.0F;
	particles.unk10 = 0.0F;
	particles.unk18 = 0.0F;
	particles.y = 0.3F;
	particles.unk14 = 0.8F;
	particles.texList = gpsTexList_Particle;
	particles.particleParams = &lbl_001D8F58;
	particles.unk73 = static_cast<u8>(~0);
	particles.baseModelMatrix = nullptr;
	particles.unk74 = 0;
	particles.unk48 = &player.x;
}

void Player_TrickLevelling(Player &player) {

    if (!(player.extremeGear == ExtremeGear::ShootingStar ||
        player.extremeGear == ExtremeGear::WindStar ||
        player.extremeGear == ExtremeGear::RoadStar ||
        player.extremeGear == ExtremeGear::Shinobi
    )) {
        return;
    }

    TrickLevelInfo *TrLInfo = &PlayerTrickLevelInfo[player.index];

    std::array<u8, 2> Tricks4Level = {0, 0};
    u8 startingLevel = player.level;

    switch(player.extremeGear) {
        using namespace ExtremeGear;
        case WindStar:
        case RoadStar:
            Tricks4Level = {12, 24};
            break;
        case ShootingStar:
            Tricks4Level = {10, 20};
            break;
        case Shinobi:
            Tricks4Level = {15, 30};
            break;
        default:
            break;
    }

    if (player.state == PlayerState::StartLine) {
        TrLInfo->trickAccumulator = 0;
        TrLInfo->isTricking = false;
    }

    if (player.state == PlayerState::FrontflipRamp || player.state == PlayerState::BackflipRamp ||
        player.state == PlayerState::ManualRamp || player.state == PlayerState::HalfPipeTrick) {
        TrLInfo->isTricking = true; // This makes sure trick landing behaviours only fire once.
    }

    // What happens once the player has left trick state.
    if (player.previousState == PlayerState::FrontflipRamp || player.previousState == PlayerState::BackflipRamp ||
        player.previousState == PlayerState::ManualRamp || player.previousState == PlayerState::HalfPipeTrick) {
        if ((player.state == PlayerState::Cruise || player.state == PlayerState::Fly || player.state == PlayerState::RailGrind) && (TrLInfo->isTricking == true)) { // Prevents constant updating

            // Update the accumulator and check the cap
			TrLInfo->trickAccumulator += player.trickCount;
            if (TrLInfo->trickAccumulator > Tricks4Level[1]) {
                TrLInfo->trickAccumulator = Tricks4Level[1];
            }

            // Shooting Star: Pay 2 Win
            if (player.extremeGear == ExtremeGear::ShootingStar
            && player.level > 0
            && player.trickCount < 4
            && player.state == PlayerState::Cruise) { // No P2W if Fly/Grind.
                player.speed += pSpeed(60);
                if (player.rings >= 20) {
                    player.rings -= 20;
                    if(!player.aiControl) PlayAudioFromDAT(Sound::ComposeSound(Sound::ID::IDKSFX, 0x39)); // Ring loss SFX
                } else {
                    TrLInfo->trickAccumulator -= 10;
                }
            }

            // Shinobi: Extra Landing Speed
            if (player.extremeGear == ExtremeGear::Shinobi) {
                player.speed += pSpeed(player.rings / 2);
            }

            // Update the player level now that we have the new amount of tricks
            if (TrLInfo->trickAccumulator >= Tricks4Level[1]) { // Level 3
                player.level = 2;
            } else if (TrLInfo->trickAccumulator >= Tricks4Level[0]) { // Level 2
                player.level = 1;
            } else { // Level 1
                player.level = 0;
            }

            // If the level is different than the one we stored, refill air if level went up and play VFX/SFX.
            if (player.level != startingLevel) {
                if(!player.aiControl) PlayAudioFromDAT(Sound::ComposeSound(Sound::ID::IDKSFX, 0xD)); // Levelling SFX
                Player_CreateTrickLevelUpParticles(player);
                if (player.level > startingLevel) {
                    player.currentAir = player.gearStats[player.level].maxAir;
                }
            }
		}

        // Specify that the player is no longer in trick state.
        TrLInfo->isTricking = false;
    }

    if (player.previousState == PlayerState::Death) { // Apply Level again on death.
		if (TrLInfo->trickAccumulator >= Tricks4Level[1]) { // Level 3
			player.level = 2;
		} else if (TrLInfo->trickAccumulator >= Tricks4Level[0]) { // Level 2
			player.level = 1;
		} else { // Level 1
			player.level = 0;
		}
		player.previousState = PlayerState::Cruise;
	}
}