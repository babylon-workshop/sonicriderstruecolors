#include "custom_music.hpp"
#include <format>
#include "cosmetics/player/exloads.hpp"
#include "lib/stdlib.hpp"
#include "riders/gamemode.hpp"
#include "riders/stage.hpp"
#include "handlers/menu/debugmenu/debugmenu.hpp"

struct ActivePad {
    Flag<Buttons> holdButtons;
    Flag<Buttons> toggleButtons;
};
extern ActivePad gsActivePad;

SubFont CustomMusicTextData;

bool CustomMusic_SkipSHOHOMusic;

[[nodiscard]] MusicMode GetMusicModeInGame() {
    return CurrentGameMode == BattleMode ? MusicMode::Battle : MusicMode::Stage;
}

// [[nodiscard]] u32 GetMusicRandomizeCountInGame() {
//     return CurrentGameMode == BattleMode ? BATTLE_MUSIC_COUNT : 4;
// }

USED void CustomMusicRandomizer(const MusicMode mode) {
    u32 songID = bss_CustomMusicID;
    const Player *SHOPlayer = nullptr;
    bool HOCheck = false;
    CustomMusic_SkipSHOHOMusic = false;
    const bool isVanillaPlaylist = DebugMenu_IsVanillaPlaylist();

    switch (mode) {
        case MusicMode::Stage: // stage music mode
                if (isVanillaPlaylist) {
                    songID = 4; // vanilla
                } else {
                    songID = 0;
                    for (auto &input: GameControllers) {
                        if (input.holdFaceButtons.hasAny(Buttons::A)) {
                            songID = 4;
                            break;
                        }
                    }
                }

            for (auto &player: getHumanPlayers()) {
                if (player.extremeGear == ExtremeGear::HangOn) {
                    HOCheck = true;
                }
                if (player.extremeGear == ExtremeGear::SuperHangOn && SHOPlayer == nullptr) {
                    SHOPlayer = &player;
                }
                // Feature: Hang-On/Super Hang-on music can now be suppressed by holding the X Button while the stage is loading.
                // Credit: Sirky
                // ------------------------------------------------------
                if (player.input->holdFaceButtons.hasAny(Buttons::X)) {
                    CustomMusic_SkipSHOHOMusic = true;
                }
                // ------------------------------------------------------
            }

            if (SHOPlayer != nullptr) {
                if (CustomMusic_SkipSHOHOMusic && !isVanillaPlaylist) {
                    break;
                }
                if (lbl_RNG_Number(100) == 5) {
                    songID = 0x7C; // ooh toxic
                    break;
                }
                songID = SHOPlayer->character + 5;

                switch (SHOPlayer->characterExload().exLoadID) {
                    case EXLoad::E10R:
                        break;
                    case EXLoad::E10B:
                        songID += 146; // SH162
                        break;
                    case EXLoad::HatsuneMiku:
                        songID += 128; // SH142
                        break;
                    default:
                        break;
                }
                break;
            }
            if (HOCheck) {
                if (CustomMusic_SkipSHOHOMusic && !isVanillaPlaylist) {
                    break;
                }
                songID = 0x7D;
                break;
            }
            break;
        case MusicMode::Menu: // menu music mode
            if (!isVanillaPlaylist) {
                songID = lbl_RNG_Number(MENU_MUSIC_COUNT);
            }
            break;
        case MusicMode::RaceEnd: // race end music mode
            // if (!isVanillaPlaylist) {
            //     songID = lbl_RNG_Number(RACE_END_MUSIC_COUNT);
            // }
            break;
        case MusicMode::Battle: // battle music mode
            // if (!isVanillaPlaylist) {
            //     songID = lbl_RNG_Number(BATTLE_MUSIC_COUNT);
            // }
            break;
        default:
            break;
    }

    bss_CustomMusicID = songID;
}

USED bool CustomMusicPlayer(const MusicMode mode) {
    const u32 &songID = bss_CustomMusicID;
    const bool isVanillaPlaylist = DebugMenu_IsVanillaPlaylist();

    switch (mode) {
        case MusicMode::Stage: // play stage music
            if (songID == 4) {
                return false;
            }                  // play vanilla music
            if (songID == 0x7C) // britney spears
            {
                PlayADX(gpasAdxtHandle_Bgm, easterEgg);
                break;
            }
            if (songID == 0x7D) {
                // hang on
                if (isVanillaPlaylist && CustomMusic_SkipSHOHOMusic) {
                    PlayVanillaStageMusic();
                } else {
                    PlayADX(gpasAdxtHandle_Bgm, HangOnMusic);
                }
                break;
            }
            if (songID > 4) { // super hang on
                if (isVanillaPlaylist) {
                    if (CustomMusic_SkipSHOHOMusic) {
                        PlayVanillaStageMusic(); // play vanilla stage music
                        break;
                    }

                    return false; // play vanilla SHO music
                }

                // play custom SHO music
                const std::string superHangOn = std::format("SH{}.ADX", songID - 5);
                PlayADX(gpasAdxtHandle_Bgm, superHangOn.c_str());
                break;
            }

            // play custom stage music
            // PlayADX(gpasAdxtHandle_Bgm, stageMusic[(CurrentStage - 1) * 4 + songID]);
            PlayADX(gpasAdxtHandle_Bgm, stageMusic[(CurrentStage - 1)]);
            break;
        case MusicMode::Menu: // play menu music
            if (songID >= MENU_MUSIC_COUNT || isVanillaPlaylist) {
                return false;
            }
            PlayADX(gpasAdxtHandle_Bgm, menuMusic[songID]);
            break;
        case MusicMode::RaceEnd: // play race end music
            return false;
        case MusicMode::Battle: // play battle music
            return false;
        default:
            break;
    }

    return true;
}

USED const char *FixInvincibilitySongReplay() {
    const u32 &songID = bss_CustomMusicID;
    return stageMusic[(CurrentStage - 1) * 4 + songID];
}

extern u8 lbl_001E9680[];

void PlayVanillaStageMusic() {
    u8 musicIndex = CurrentGameMode == BattleMode ? 8 : lbl_001E9680[CurrentStage - 1];
    PlayADX(gpasAdxtHandle_Bgm, lbl_001E99BC[musicIndex]);
}

void CustomMusicChanger_OnPauseMenu() {
    u32 songID = bss_CustomMusicID;
    Player *player1 = players.data();

    if (CurrentGameMode != BattleMode) {
        // accounts for if SHO/HO music is playing
        if (songID > 4) {
            return;
        }
    }

    if (player1->input->toggleFaceButtons.hasAny(Buttons::Y)) {
        songID++;
        if (CurrentGameMode != BattleMode) {
            if (songID > 4)
                songID = 0;
            bss_CustomMusicID = songID;
            if (!CustomMusicPlayer(MusicMode::Stage)) {
                PlayVanillaStageMusic();
            }
        } else {
            bss_CustomMusicID = songID;
            CustomMusicPlayer(MusicMode::Battle);
        }
    }
}

void CustomMusicChanger_MainMenu() {
    if (gsActivePad.toggleButtons.hasAny(Buttons::Y)) {
        u32 songID = bss_CustomMusicID;
        songID++;
        if (songID >= MENU_MUSIC_COUNT)
            songID = 0;
        bss_CustomMusicID = songID;
        CustomMusicPlayer(MusicMode::Menu);
    }
}
