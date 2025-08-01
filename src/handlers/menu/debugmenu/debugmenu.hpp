#pragma once

#include <optional>
#include "riders/controller.hpp"
#include "riders/object.hpp"
#include "riders/player.hpp"

namespace DebugMenuOptions {
    enum Page1 {
        DisableMusic,                         //= 1 << 0,
        MagneticImpulse,                      //= 1 << 1,
        Autopilot,                            //= 1 << 2,
        ExtremeDetach,                        //= 1 << 3,
        TornadoIgnore,                        //= 1 << 4,
        TimerActivity_ActiveInSingleplayer,   //= 1 << 5,
        TimerActivity_ActiveIn1v1,            //= 1 << 6,
        TimerActivity_ActiveIn1v1Middle,      //= 1 << 7,
        TimerActivity_ActiveIn3OrMorePlayers, //= 1 << 8,
        DisableHUDPartial,
        DisableHUDFull,
        InfiniteAir,
        InfiniteRings,
        AlwaysMaxMI,
        MusicPlaylist, // if this enum is toggled it's vanilla playlist
        ClutchAsTexture,
        ClutchAsAirGauge,
        PTRMode,
        VanillaHazardsOn,
        VanillaHazardsSkyRoadTurb,
        VanillaHazardsDigiHands,
        DisableAttacks,
        AttackInRun,
        DisableFog,
        AddAFriend,
        EnableAllGears
    };
    constexpr auto PAGE1OPTIONCOUNT = 18;
    constexpr auto DefaultPage1Options =
            1 << TimerActivity_ActiveInSingleplayer | 1 << ClutchAsAirGauge | 1 << AttackInRun;
} // namespace DebugMenuOptions

namespace DebugMenuDef {
    constexpr auto TEXT_Y      = 100;
    constexpr auto TEXT_HEIGHT = 20;
} // namespace DebugMenuDef

struct DebugMenuData {
    std::array<std::span<u8>, DebugMenuOptions::PAGE1OPTIONCOUNT> page1Options;

    u8 state           = 0;
    u8 selectedItemRow = 0;
    u8 maximumItems    = 0;
    u8 dirHoldTimer    = 0;

    // bit field that corresponds to enum DebugMenuOptions
    u32 toggledPageOptions = DebugMenuOptions::DefaultPage1Options;

    s32 itemYOffset = 0;
};

struct Text2dFileData {
    std::array<void *, 2> textData;
    std::array<void *, 2> extraTextData;
};

struct AllPlayerInputs {
    Flag<Buttons> holdButtons;
    Flag<Buttons> toggleButtons;
};

struct TitleSequenceObject1 {
    fillerData<0xD> filler;
    s8 currentButtonIndex;
    s8 lastButtonIndex;
    s8 currentMode;
    fillerData<0x2C> filler2;
    u8 chosenGamemode;
};

extern Text2dFileData DebugMenu_TextData;
extern DebugMenuData DebugMenu_Data;

bool DebugMenu_CheckOption(u32 option);
void DebugMenu_ToggleOption(std::span<u8> options);
void DebugMenu_ToggleOptionSet(std::span<u8> options, u32 direction);
void DebugMenu_HandleAllToggles(std::span<u8> options, u32 direction);
u32 DebugMenu_FetchTextIDAllToggles(std::span<u8> options);
ASMUsed void DebugMenu_Handler(ObjectNode *object, AllPlayerInputs *inputs);
std::optional<u8> DebugMenu_FetchOptionFromOptionSet(std::span<u8> options);
u32 DebugMenu_FetchTextID(u32 option);
ASMUsed void DebugMenu_RenderDescription();
[[nodiscard]] bool DebugMenu_IsVanillaPlaylist();
