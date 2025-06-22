#include "defaultgearrotation.hpp"
#include "containers/graphicalobject.hpp"
#include "lib/lib.hpp"
#include "exloads.hpp"

std::array<u16, MaxPlayerCount> PlayerDefaultIDs;

USED void InitFirstDefaultGear(Player *player) {

    u16* playerDefaultID = &PlayerDefaultIDs[player->index];

    *playerDefaultID = player->character;

    if (player->character == Character::SuperSonic || player->character == Character::Total) {
        *playerDefaultID = 0;
    }
    else if (player->character == Character::Eggman) {   // This should be fine as rotating Defaults
        *playerDefaultID = 7;                   // is not possible if Eggman is selected.
    }
}

USED void RotateNextDefaultGear(GraphicalObject *object) {
    if(object->active == 0) { return; }

	Player &player = players[object->idStruct.idIndex];
	const u8 &controllerPort = player.input->port;

    if (player.extremeGear != ExtremeGear::Default) return;
    if (player.character == Character::Eggman || player.character == Character::E10R) return;

    // SYB: I dunno what this does but I'm copying it for safety reasons
    #pragma clang diagnostic push
    #pragma ide diagnostic ignored "cppcoreguidelines-pro-type-reinterpret-cast"
	const auto *cssObject = static_cast<CSSObject *>(gp2DSys->objectGroupPtrs[7][0]);
    #pragma clang diagnostic pop

    u16* playerDefaultID = &PlayerDefaultIDs[player.index];

    // Update what ID we're on if pressing START (forward)
    if (player.input->toggleFaceButtons.hasAny(Buttons::Start) && object->idStruct.graphicalDataID == NotLockedGearSelectionID) {
        player.playerType = 0; // Bodge to fix CSS making you a CPU fsr

        *playerDefaultID += 1;
        if (*playerDefaultID >= Character::Total) {
            *playerDefaultID = 0;
        }
        else if (*playerDefaultID == Character::SuperSonic || *playerDefaultID == Character::Eggman) {
            *playerDefaultID += 1;
        }
    }

    // Update what ID we're on if pressing Y (backward)
    // if (player.input->toggleFaceButtons.hasAny(YButton) && object->idStruct.graphicalDataID == NotLockedGearSelectionID) {
    //     player.playerType = 0; // Bodge to fix CSS making you a CPU fsr

    //     if (*playerDefaultID == 0) {
    //         *playerDefaultID = TotalCharacterAmount - 1;
    //     }
    //     else {
    //         *playerDefaultID -= 1;
    //     }

    //     if (*playerDefaultID == SuperSonic || *playerDefaultID == Eggman) {
    //         *playerDefaultID -= 1;
    //     }
    // }

    // Update graphics
    if(object->idStruct.graphicalDataID == NotLockedGearSelectionID) {
        object->textureIDs[0].textureSlot1 = CharacterDefaultGearData[*playerDefaultID][0]; // Portrait
        object->textureIDs[0].textureSlot5 = CharacterDefaultGearData[*playerDefaultID][1]; // GearText
    }
    else if (object->idStruct.graphicalDataID == LockedGearSelectionID) {
        object->textureIDs[0].textureSlot4 = CharacterDefaultGearData[*playerDefaultID][1]; // GearText
    }
}