#include "skilllink.hpp"
#include "handlers/player/initgeardata.hpp"
#include "lib/sound.hpp"

std::array<SkillLinkInfo, MaxPlayerCount> PlayerSkillLinkInfo;

void Player_SkillLink(Player &player) {

    SkillLinkInfo *SkLInfo = &PlayerSkillLinkInfo[player.index];

    if (player.state == PlayerState::StartLine) {
        SkLInfo->prevItem = ItemID::Invincibility;
    }

}