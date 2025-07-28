#pragma once

#include "handlers/ingame/customtext.hpp"

using ADXTHandle = void*;

ASMDefined void PlayADX(void *gpasAdxtHandle_Bgm, const char[]);

/// Pauses currently playing ADX file on given ADXT handle. If pause parameter is set, it pauses the ADX file, if it's false, it unpauses it.
ASMDefined void ADXT_Pause(ADXTHandle adxtHandle, bool pause);

ASMDefined void ADXT_Stop(ADXTHandle adxtHandle);

ASMDefined ADXTHandle gpasAdxtHandle_Bgm;
ASMDefined ADXTHandle lbl_8021BC0C;
ASMDefined ADXTHandle lbl_8021BC08;

ASMDefined u32 bss_CustomMusicID;
ASMDefined std::array<const char *, 87> lbl_001E99BC;
extern SubFont CustomMusicTextData;

enum class MusicMode : u32 {
    Stage,
    Menu,
    RaceEnd,
    Battle
};

ASMUsed void CustomMusicRandomizer(MusicMode mode);
ASMUsed bool CustomMusicPlayer(MusicMode mode);
ASMUsed const char *FixInvincibilitySongReplay();
ASMUsed void CustomMusicChanger_OnPauseMenu();
ASMUsed void CustomMusicChanger_MainMenu();
void PlayVanillaStageMusic();
[[nodiscard]] MusicMode GetMusicModeInGame();
[[nodiscard]] u32 GetMusicRandomizeCountInGame();

constexpr auto STAGE_MUSIC_COUNT = 16;
constexpr auto MENU_MUSIC_COUNT = 2;

constexpr std::array<const char *, STAGE_MUSIC_COUNT> stageMusic = {
		"METALC.ADX",
		"SPLASHC.ADX",
		"EGGF.ADX",
		"GREENC.ADX",
		"SANDR.ADX",
		"BABYLONG.ADX",
		"DIGITALD.ADX",
		"SEGAC.ADX",
		"NIGHTC.ADX",
		"REDC.ADX",
		"ICEF.ADX",
		"WHITEC.ADX",
		"DARKD.ADX",
		"SKYR.ADX",
		"GUARDIAN.ADX",
		"SEGAI.ADX"
};

constexpr std::array<const char *, MENU_MUSIC_COUNT> menuMusic = {
		"HEALTH.ADX",
		"NIN.ADX"
};

constexpr const char *easterEgg = "7C.ADX";

constexpr const char *HangOnMusic = "S22.ADX";