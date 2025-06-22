#include "sybskin.hpp"
#include "cosmetics/player/exloads.hpp"

std::array<u8, MaxPlayerCount> PlayerSkinIDs;

ASMUsed void SetPlayerSkin(Player *player) {
    u8* playerSkinID = &PlayerSkinIDs[player->index];
    
    if (player->character == Character::E10R ||
        player->character == Character::E10G ||
        player->character == Character::SuperSonic
    ) {
        *playerSkinID = 0;
        return;
    }

    if(player->input->holdFaceButtons.hasAny(Buttons::X)) {
        *playerSkinID = 1;
    }
    else if(player->input->holdFaceButtons.hasAny(Buttons::Y)) {
        *playerSkinID = 2;
    }
    else {
        *playerSkinID = 0;
    }
}