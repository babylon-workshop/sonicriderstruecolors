#pragma once

#include "riders/player.hpp"

ASMDefined void func_Particle_Task();
ASMDefined void* gpsTexList_Particle;
ASMDefined void* lbl_001D8F58;

constexpr m2darray<f32, 3, 2> CoverF_Speeds = {{
		// top speed, boost speed
		{pSpeed(235), pSpeed(220)}, // solution cruise
		{pSpeed(155), pSpeed(265)}, // solution turbo
		{pSpeed(200), pSpeed(240)}, // solution battle
}};
constexpr m2darray<f32, 3, 2> CoverF_SpeedsBoostArchetype = {{
        // top speed, boost speed
        {pSpeed(235), pSpeed(237)},// solution cruise
        {pSpeed(155), pSpeed(267)},// solution turbo
        {pSpeed(200), pSpeed(242)},// solution battle
}};

void Player_CoverF(Player &player);
