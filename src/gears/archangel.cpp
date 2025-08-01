#include "archangel.hpp"
#include "handlers/player/initgeardata.hpp"
#include "lib/sound.hpp"
#include "lib/stdlib.hpp"
#include "riders/object.hpp"

std::array<ArchAngelInfo, MaxPlayerCount> PlayerArchAngelInfo;

void Player_CreateArchAngelParticles(Player &player) {
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

void Player_ArchAngel_Detransform(Player &player) {
    ArchAngelInfo *ArAInfo = &PlayerArchAngelInfo[player.index];

    ArAInfo->isTransformed = false;
    if (player.level == 2) {
        player.unkBAC ^= 0x0100; //Handedness Swap!
    }
    player.level = 1;
    player.specialFlags = (SpecialFlags::noSpecialFlags);
    if(!player.aiControl) PlayAudioFromDAT(Sound::ComposeSound(Sound::ID::IDKSFX, 0xD));
    Player_CreateArchAngelParticles(player);
    player.currentAir = player.gearStats[player.level].maxAir;
}

void Player_ArchAngel(Player &player) {
    if (player.extremeGear != ExtremeGear::Archangel) {return;}

    ArchAngelInfo *ArAInfo = &PlayerArchAngelInfo[player.index];

	if (player.input->toggleFaceButtons & Buttons::DPadUp) {
        if (ArAInfo->isTransformed == true) { // Manual Detransform.
            Player_ArchAngel_Detransform(player);
            return;
        }
        if (player.rings <= 10) {
            return;
        }

        // Angel/Devil Mode behaviours.
        if (lbl_RNG_Number(2) == 0) { // Pacifist Mode
            if(!player.aiControl) PlayAudioFromDAT(Sound::ComposeSound(Sound::ID::IDKSFX, 0x40)); // UFO SFX
            player.specialFlags |= SpecialFlags::noSpeedLossChargingJump;
            player.level = 0;
            ArAInfo->isTransformed = true;
        }
        else { // Genocide Mode
            if(!player.aiControl) PlayAudioFromDAT(Sound::ComposeSound(Sound::ID::IDKSFX, 0x1C)); // Roar SFX
            player.specialFlags |= SpecialFlags::berserkerEffect;
            player.level = 2;
            player.unkBAC ^= 0x0100; //Handedness Swap!
            ArAInfo->isTransformed = true;
        }

        // Generic transformation behaviour.
        player.currentAir += 50000;
        Player_CreateArchAngelParticles(player);
        player.rings -= 10;
    }

    // Initialising behaviours.
    if (player.state == PlayerState::StartLine) {
        player.level = 1;
        player.currentAir = player.gearStats[player.level].maxAir;
        ArAInfo->isTransformed = false; // Not in transformed state in the beginning.
        ArAInfo->ringDrainTickRate = 30; // Initialise Ring Drain counter so we don't have to later.
	}

    // We handle the Ring Drain while transformed here.
    if (ArAInfo->isTransformed == true) {
        ArAInfo->ringDrainTickRate -= 1;
        if (ArAInfo->ringDrainTickRate == 0) {
            player.rings -= 1;
            ArAInfo->ringDrainTickRate = 30;
            if (player.rings == 0) { // Detransform Behaviours go here.
                Player_ArchAngel_Detransform(player);
            }
        }
    }

    // Angel Mode exhaust & punishment checker.
    if (player.level == 0) {
        if (player.state == PlayerState::AttackingPlayer || player.state == PlayerState::AttackedByPlayer) {
            player.rings = 0;
            Player_ArchAngel_Detransform(player);
            if(!player.aiControl) PlayAudioFromDAT(Sound::ComposeSound(Sound::ID::IDKSFX, 0x0F)); // Superbad Buzz
        }
    }

    // Devil Mode behaviours.
    if (player.level == 2) {

        // Punishment checker.
        if (player.state == PlayerState::Cruise && player.speed < pSpeed(150)) {
            player.rings = 0;
            Player_ArchAngel_Detransform(player);
            if(!player.aiControl) PlayAudioFromDAT(Sound::ComposeSound(Sound::ID::IDKSFX, 0x0F)); // Superbad Buzz
        }

        // Ring gain on hit.
        if (player.previousState == PlayerState::AttackingPlayer) {
            if(!player.aiControl) PlayAudioFromDAT(Sound::ComposeSound(Sound::ID::VSFX, 0x0A));
            player.rings += 30;
            player.previousState = PlayerState::Cruise;
        }
    }
}