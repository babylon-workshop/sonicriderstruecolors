#include "challenger.hpp"
#include "handlers/player/initgeardata.hpp"
#include "lib/sound.hpp"
#include "lib/stdlib.hpp"
#include "riders/object.hpp"

std::array<ChallengerInfo, MaxPlayerCount> PlayerChallengerInfo;

void Player_CreateChallengerParticles(Player &player) {
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

void Player_Challenger_Roll(Player &player) {

    ChallengerInfo *ChlInfo = &PlayerChallengerInfo[player.index];

    switch (lbl_RNG_Number(4)) {
            case 0:
                player.level = 0;
                player.gearSpecificFlags[Challenger::Level4] = false;
                break;
            case 1:
                player.level = 1;
                player.gearSpecificFlags[Challenger::Level4] = false;
                break;
            case 2:
                player.level = 2;
                player.gearSpecificFlags[Challenger::Level4] = false;
                player.gearStats[2].boostSpeed = pSpeed(250);
                break;
            case 3:
                player.level = 2;
                player.gearSpecificFlags[Challenger::Level4] = true;
                player.gearStats[2].boostSpeed = pSpeed(265);
                break;
            default:
                break;
        }

        // Randomise Type
        switch (lbl_RNG_Number(3)) {
            case 0:
                player.typeAttributes = Type::Speed;
                break;
            case 1:
                player.typeAttributes = Type::Fly;
                break;
            case 2:
                player.typeAttributes = Type::Power;
                break;
            default:
                break;
        }

        // Sound and FX
        Player_CreateChallengerParticles(player);
        if (player.typeAttributes == Type::Speed) {
            if(!player.aiControl) PlayAudioFromDAT(Sound::ComposeSound(Sound::ID::IDKSFX, 0x3D)); // Speed Shoes SFX
        } else if (player.typeAttributes == Type::Fly) {
            if(!player.aiControl) PlayAudioFromDAT(Sound::ComposeSound(Sound::ID::IDKSFX, 0x3C)); // Fly Hoop SFX
        } else if (player.typeAttributes == Type::Power) {
            if(!player.aiControl) PlayAudioFromDAT(Sound::ComposeSound(Sound::ID::IDKSFX, 0x1C)); // Roar SFX
        }

        // Reset timer
        ChlInfo->timerFrames = 901;     // 15 seconds + 1 
}

void Player_Challenger(Player &player) {
    if (player.extremeGear != ExtremeGear::Challenger) {return;}

    ChallengerInfo *ChlInfo = &PlayerChallengerInfo[player.index];

    // Roll Type and Level if necessary
    if (ChlInfo->timerFrames == 0 && player.state != PlayerState::StartLine) {
        Player_Challenger_Roll(player);
    }

    // Manual refill
    if (player.input->toggleFaceButtons & Buttons::DPadUp && player.rings >= 30) {
        player.currentAir = player.gearStats[player.level].maxAir;
        player.rings -= 30;
    if(!player.aiControl) PlayAudioFromDAT(Sound::ComposeSound(Sound::ID::IDKSFX, 0x39)); // Ring loss SFX
    }

    // 3 second countdown
    if (ChlInfo->timerFrames == 60 || ChlInfo->timerFrames == 120 || ChlInfo->timerFrames == 180) {
        if (InGamePlayerCount <= 2) {
            if(!player.aiControl) PlayAudioFromDAT(Sound::ComposeSound(Sound::ID::VSFX, 0x5)); // Start Line beep
        }
    }

    // Timer behaviour
    if (player.state == PlayerState::StartLine) {
        ChlInfo->timerFrames = 900;     // 15 seconds
    } else {
        ChlInfo->timerFrames -= 1;
    }

    // Death reroll after 3 seconds
    if (player.state == PlayerState::Death) {
        ChlInfo->timerFrames = 181;
        player.gearSpecificFlags[Challenger::Level4] = false;
    }
}