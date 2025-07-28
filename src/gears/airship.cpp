#include "airship.hpp"
#include "handlers/player/initgeardata.hpp"
#include "lib/sound.hpp"

std::array<AirshipInfo, MaxPlayerCount> PlayerAirshipInfo;

void Player_Airship(Player &player) {
    if (player.extremeGear != ExtremeGear::Airship) {return;}

    AirshipInfo *AirshipInfo = &PlayerAirshipInfo[player.index];

    if (AirshipInfo->airdashCooldown != 0) {
        AirshipInfo->airdashCooldown -= 1;
    }

    if (player.input->toggleFaceButtons & Buttons::X) {
        if (player.state == PlayerState::Fall || player.state == PlayerState::Jump || 
            player.state == PlayerState::FrontflipRamp || player.state == PlayerState::BackflipRamp || 
            player.state == PlayerState::ManualRamp || player.state == PlayerState::HalfPipeTrick) {
            if (AirshipInfo->airdashCooldown == 0 && player.currentAir > player.gearStats[player.level].boostCost * 2) {
                player.speed += pSpeed(150);
                player.verticalSpeed -= 0.2;
                // player.verticalSpeed += 0.5; // Air Dash height bonus. Legacy!
                player.currentAir -= player.gearStats[player.level].boostCost * 2;
                AirshipInfo->airdashCooldown = 180;
                if(!player.aiControl) PlayAudioFromDAT(Sound::ComposeSound(Sound::ID::IDKSFX, 0x3B)); //Dash panel SFX
            }
        }
    }

}