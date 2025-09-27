#include "sybskin.hpp"
#include "cosmetics/player/exloads.hpp"

std::array<u8, MaxPlayerCount> PlayerSkinIDs;

ASMUsed void SetPlayerSkin(Player *player) {
    return;
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

ASMUsed void NextPlayerSkin(GraphicalObject *object) {
    if(object->active == 0) { return; }

    const auto playerIndex = object->idStruct.idIndex;
    Player &player = players[playerIndex];
    u8* playerSkinID = &PlayerSkinIDs[player.index];

    if (player.character == Character::E10R || player.character > Character::Tikal) {return;}

    if(player.input->toggleFaceButtons.hasAny(Buttons::X)) {
        *playerSkinID += 1;
        if (*playerSkinID > 2) {
            *playerSkinID = 0;
        }
    }

	object->textureIDs[0].textureSlot1 = CharacterskinIconData[player.character][*playerSkinID];

}