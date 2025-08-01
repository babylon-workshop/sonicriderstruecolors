#include "projektred.hpp"
#include "handlers/player/initgeardata.hpp"
#include "lib/sound.hpp"

std::array<ProjektRedInfo, MaxPlayerCount> PlayerProjektRedInfo;

void Player_ProjektRed(Player &player) {
    if (player.extremeGear != ExtremeGear::Executor) {return;}

    ProjektRedInfo *RedInfo = &PlayerProjektRedInfo[player.index];

    if (player.state == PlayerState::StartLine) {
        RedInfo->isDead = false;
        RedInfo->redeployState = false;
    }

    // if (!(player.state == StartLine || player.state == Death) && player.input->toggleFaceButtons & XButton) {
    //     player.previousState = player.state;
    //     player.state = Death;
    // }

    if (player.state == PlayerState::Death) {
        RedInfo->isDead = true;
    }

    if (player.previousState == PlayerState::Death && RedInfo->isDead == true) {
        RedInfo->isDead = false;
        player.speed += pSpeed(350);
        player.rings += 30;
        RedInfo->redeployState = true;
        player.level = 2;
        player.currentAir = player.gearStats[player.level].maxAir;
        if(!player.aiControl) PlayAudioFromDAT(Sound::ComposeSound(Sound::ID::SFX, 0x1A)); // Wolf SFX
    }

    if (RedInfo->redeployState == true) {
        if (RedInfo->ringTimer == 0 && player.state == PlayerState::Cruise) {
            player.rings -= 1;
        }
        player.level = 2;

        if (player.rings == 0) {
            RedInfo->redeployState = false;
        }
    }
    else {
        player.level = 0;
    }

    RedInfo->ringTimer += 1;
    if (RedInfo->ringTimer == 10) {
        RedInfo->ringTimer = 0;
    }
}