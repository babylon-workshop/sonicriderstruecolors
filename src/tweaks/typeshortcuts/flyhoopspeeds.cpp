#include <mechanics/dash/grindraildash.hpp>

#include "cosmetics/player/exloads.hpp"
#include "lib/sound.hpp"
#include "lib/stdlib.hpp"
#include "mechanics/characters/gizoidreplication.hpp"
#include "mechanics/dash/flyhoopdash.hpp"
#include "mechanics/magneticimpulse.hpp"
#include "riders/object.hpp"
#include "riders/stage.hpp"
#include "gears/omnipotence.hpp"
#include "gears/blastGaugeGears.hpp"
#include "gears/supermetal.hpp"
#include "handlers/player/specialflagtweaks.hpp"

constexpr std::array<f32, TotalStageAmount> StageBaseSpeeds = {
		0.0f,      // test stage
		0.231482f, // metal city
		0.0f,      // splash canyon
		0.925926f, // egg factory
		0.347222f, // green cave
		0.185185189f,// sand ruins 0.0462963f 0.185185189f
		0.185185f, // babylon garden
		0.324074f, // digital dimension
		0.509306f, // sega carnival
		1.85189f,  // night chase
		0.0925926f,// red canyon
		0.972222f, // ice factory
		0.0462963f,// white cave
		0.0f,      // dark desert
		0.0f,      // sky road
		0.925926f, // babylon guardian
		0.0925927f,// sega illusion
};

constexpr std::array<f32, TotalStageAmount> SpecificFlyHoopSpeeds = {
		0.0f,      // test stage
		0.462963f, // metal city
		0.0f,      // splash canyon
		-0.462963f,// egg factory
		0.0f,      // green cave
		0.0f,      // sand ruins
		0.0f,      // babylon garden
		0.0f,      // digital dimension
		0.0f,      // sega carnival
		0.0f,      // night chase
		0.0f,      // red canyon
		0.0f,      // ice factory
		0.185187f, // white cave
		0.0f,      // dark desert
		0.0f,      // sky road
		0.0f,      // babylon guardian
		0.833334f, // sega illusion
};

constexpr f32 BaseFlyHoopVerticalSpeeds[TotalStageAmount] = {
		0.05f,// test stage
		0.35f,// metal city
		0.1f, // splash canyon
		0.5f, // egg factory
		0.4f, // green cave
		0.1f, // sand ruins
		0.25f,// babylon garden
		0.2f, // digital dimension
		0.05f,// sega carnival
		0.05f,// night chase
		0.05f,// red canyon
		0.4f, // ice factory
		0.05f,// white cave
		0.05f,// dark desert
		0.05f,// sky road
		0.05f,// babylon guardian
		0.45f,// sega illusion
};

ASMUsed f32 CustomFlyHoopVerticalSpeeds(const ObjectNode &object, const Player &player, const f32 flyHoopSpeed, const f32 currentSpeed, const f32 angle) {
	f32 multiplier = BaseFlyHoopVerticalSpeeds[CurrentStage];
    f32 const baseHoopCalc = !player.specialFlags.hasAny(SpecialFlags::ringGear) ? -1.0f * (static_cast<f32>(player.level) * pSpeed(10.0f)) : pSpeed(-10.0f);
    // (-0.0902777777777778f)
	switch(CurrentStage) {
		case MetalCity:
			switch(object.object_id) {
				case 0x121:
					multiplier = 0.1f;
					break;
				case 0x124:
					multiplier = 0.15f;
					break;
				default:
					break;
			}
			break;

		case GreenCave:
			switch(object.object_id) {
				case 0xEB:
					multiplier = -0.1f;
					break;
				default:
					break;
			}
			break;

		case SandRuins:
			switch(object.object_id) {
				case 0x136:
					multiplier = -0.8f;
					break;
				case 0x138:
					multiplier = 1.5f;
					break;
				case 0x13D:
					multiplier = 0.2f;
					break;
				default:
					break;
			}
			break;

		case NightChase:
			switch(object.object_id) {
				case 0x26:
					multiplier = 0.4f;
					break;
				case 0x27:
					multiplier = 0.2f;
					break;
				default:
					break;
			}
			break;

		case IceFactory:
			switch(object.object_id) {
				case 0x16E:
				case 0x16F:
					multiplier = 0.2f;
					break;
				default:
					break;
			}
			break;

		case SkyRoad:
			switch(object.object_id) {
				case 0xD4:
					multiplier = -0.5f;
					break;
				case 0xD5:
					multiplier = 0.5f;
					break;
				case 0xD6:
					multiplier = 0.6f;
					break;
				default:
					break;
			}
			break;

		case SegaCarnival:
			switch(object.object_id) {
				case 0x5F:
				case 0x60:
					multiplier = 0.4f;
					break;
				case 0x61:
					multiplier = 0.2f;
					break;
				default:
					break;
			}
			break;
		case SplashCanyon:
			switch(object.object_id) {
				case 0xA0:// first hoop, last path
					multiplier = 0.6f;
					break;
				case 0x9F:
					multiplier = 0.8f;
					break;
				case 0x9E:
					multiplier = 0.8f;
					break;
				default:
					break;
			}
			break;
		case DarkDesert:
			switch(object.object_id) {
				case 0xF6:
					multiplier = 0.5f;
					break;
				case 0x2D0:
					multiplier = 0.3f;
					break;
			}
			break;
		// case BabylonGarden:
		// 	if (object.object_id >= 0xE1 && object.object_id <= 0xE3) {
		// 		multiplier = 0.45f;
		// 	}
		// 	break;
		default:
			break;
	}
	return angle
		   * (-flyHoopSpeed + ((-currentSpeed + (-0.0902777777777778f + baseHoopCalc)) * multiplier));
}

inline f32 SpecificFlyHoops(const ObjectNode &object, Player &player, f32 currentHoopSpeed) {
	const f32 &flyHoopSpeed = SpecificFlyHoopSpeeds[CurrentStage];
	bool toAddSpeed = false;
	const u32 &object_id = object.object_id;

	switch(CurrentStage) {
		case SegaIllusion:
			if(object_id >= 0xAA && object_id <= 0xAD) {
				toAddSpeed = true;
			}

			break;
		case EggFactory:
			if(object_id >= 0x125 && object_id <= 0x126) {
				toAddSpeed = true;
				break;
			}
			if(object_id >= 0x2C5 && object_id <= 0x2C7) {
				toAddSpeed = true;
			}
			break;
		case WhiteCave:
			if(object_id == 0x27) {
				player.changeInAir_gain += 30000;// 30 air
			} else {
				toAddSpeed = true;
			}
			break;
		case MetalCity:
			if(object_id >= 0x122 && object_id <= 0x124) {
				toAddSpeed = true;
				currentHoopSpeed *= 1.2f;
			}
			break;
		case SplashCanyon:
			if(object_id >= 0x9E && object_id <= 0xA0) {
				// last fly route
				currentHoopSpeed *= 3.6f;
			} 
			// else if(object_id == 0xB6 || object_id == 0xB7 || object_id == 0x23B) {
			// 	// first fly route
			// 	currentHoopSpeed *= 1.7f;
			// }
			break;
		case SkyRoad:
			if(object_id >= 0xD4 && object_id <= 0xD6) {
				currentHoopSpeed *= 1.2f;
			}
			break;
		case SandRuins:
			if(object_id >= 0x13A && object_id <= 0x13D) {
				currentHoopSpeed *= 1.5f;
			}
			break;
		case DigitalDimension:
			if(object_id >= 0x130 && object_id <= 0x133) {
				currentHoopSpeed *= 1.5f;
			}
			break;
		case DarkDesert:
			if((object_id >= 0xF6 && object_id <= 0xF8)
				|| object_id == 0x2D0){
				currentHoopSpeed *= 2.0f;
			}
			// BIGASS NOTE: THE OBJECT IDS CHANGE IF YOU CHANGE THE STAGE.
			if(object_id >= 0x2D1 && object_id <= 0x2D3) {
				currentHoopSpeed *= 0.875f;
			}
			break;
		// case BabylonGarden:
		// 	if (object_id >= 0xE1 && object_id <= 0xE3) {
		// 		currentHoopSpeed *= 1.5f;
		// 	}
			break;
		default:
			break;
	}

	if(toAddSpeed) {
		currentHoopSpeed += flyHoopSpeed;
	}

	return currentHoopSpeed;
}

inline f32 FlyCharacter_DualType(const Player &player, f32 currentFlyHoopSpeed) {
	if(player.characterptr->type == Character::Type::Fly) {
		currentFlyHoopSpeed *= 0.975f;
	} else {
		currentFlyHoopSpeed *= 0.95f;
	}
	return currentFlyHoopSpeed;
}

inline f32 FlyCharacter_AllType(const Player &player, f32 currentFlyHoopSpeed) {
	// if (player.character == MetalSonic && player.extremeGear == ChaosEmerald) {
	// 	currentFlyHoopSpeed *= 0.925f + (player.objectLinkCount * 0.08f);
	// }
	// else {
	const SpecialFlagInfo &spfInfo = PlayerSpecialFlagInfo[player.index];
	if(player.characterptr->type == Character::Type::Fly && player.extremeGear == ExtremeGear::Omnipotence) {
		currentFlyHoopSpeed *= 0.95f;
	}
	else currentFlyHoopSpeed *= 0.925f;
	// }
	return currentFlyHoopSpeed;
}

ASMUsed void CustomFlyHoopSpeeds(Player &player, ObjectNode &object, const f32 currentFlyHoopSpeed, const f32 angle) {
	const f32 flyHoopSpeed = currentFlyHoopSpeed * angle;
	f32 newFlyHoopSpeed = flyHoopSpeed + StageBaseSpeeds[CurrentStage];
	newFlyHoopSpeed = SpecificFlyHoops(object, player, newFlyHoopSpeed);
	if(player.character == Character::Emerl) {
		const GizoidReplicationInfo &grInfo = PlayerGizoidReplication[player.index];
		if(grInfo.isEnabled && InGamePlayerCount >= 2) {
			switch(player.getTypeCount()) {
				case 2:
					newFlyHoopSpeed *= GR_TypeShortcutSpeedMultiplier;
					break;
				case 3:
					newFlyHoopSpeed *= GR_TypeShortcutSpeedMultiplierDual;
					break;
				default:
					break;
			}
		}
	}

	switch(player.extremeGear) {
		using namespace ExtremeGear;
		case CoverS:
			if(player.characterptr->type != Character::Type::Fly) {
				newFlyHoopSpeed *= 1.115f;
			}
			break;
		case Access:
			if(player.typeAttributes == Type::Fly) {
				// mono access
				newFlyHoopSpeed *= 1.085f;
			}
			break;
		case ChaosEmerald:
			if(player.character == Character::MetalSonic) {
				if (player.gearExload().exLoadID == EXLoad::StardustSpeeder) {
					const NeoMetalInfo &neoInfo = PlayerNeoMetalInfo[player.index];
					if(neoInfo.formState == 2) {
						newFlyHoopSpeed += (static_cast<f32>(player.objectLinkCount) * 0.10f); // NEO III
					}
				} else newFlyHoopSpeed += (static_cast<f32>(player.objectLinkCount) * 0.08f);
			}
		// else if(player->character == Character::Tails && player->superFormState != 0) {
		// 		newFlyHoopSpeed *= 1.1f;
		// 	}
			break;
		case Omnipotence: {
			if(const OmnipotenceInfo &OMNInfo = PlayerOMNInfo[player.index]; OMNInfo.lastShortcutType != 2) {
				// if (player.character == E10G) {newFlyHoopSpeed *= 1.05f;}
				// else 
				if (OMNInfo.lastShortcutType != 0) {newFlyHoopSpeed *= 1.05f;}
			}
			break;
		}
		// case SuperHangOn:
		// {
		//     HHOInfo *hhoInfo = &PlayerHHOInfo[player->index];
		//     if (exLoads.gearExLoadID == HyperHangOn && player->characterptr->type == 0x1 && hhoInfo->extraType == FlyType && hhoInfo->saturnMegadriveStatus == 2) newFlyHoopSpeed *= 1.085f;
		//     break;
		// }
		default:
			break;
	}

	switch(player.getTypeCount()) {
		case 2:
			newFlyHoopSpeed = FlyCharacter_DualType(player, newFlyHoopSpeed);
			break;
		case 3:
			newFlyHoopSpeed = FlyCharacter_AllType(player, newFlyHoopSpeed);
			break;
		default:
			break;
	}

	// Experimental new hoop dash V2
	PlayerFlyHoopDashProperties &properties = playerFlyHoopDashProperties[player.index];
	if(player.input->holdFaceButtons.hasAny(Buttons::B, Buttons::X, Buttons::L)) {
		newFlyHoopSpeed *= 1.2f;
		PlayAudioFromDAT(Sound::SFX::RailHoopDash);// dash sfx
		Player_InitBoostParticles(player);
		// properties.gainDelay are the amount of frames it delays the air gain.
		// change this value here to change the delay time
		if(!player.specialFlags.hasAny(SpecialFlags::ringGear)) {
			properties.gainDelay = 30.0f;
		}

		// don't worry about this duration here
		// properties.duration += 1;

		// This handles the air subtraction in magneticimpulse.cpp, tells it to subtract air if true.
		properties.hasUsed = true;

		// "player.magneticImpulse_timer - 60.0f" is the time (in frames) it takes from the MI timer
		// change this value here to change the amount of time it takes
		f32 newMI;
		const auto &[currentGauge] = PlayerBlastGaugeInfo[player.index];
		if(player.character == Character::SuperSonic
		    && player.extremeGear == ExtremeGear::ChaosEmerald
			&& currentGauge > 0
			&& player.gearExload().exLoadID != EXLoad::HyperSonic
			)
			{newMI = player.magneticImpulse_timer;}
		else {newMI = player.magneticImpulse_timer - 60.0f;}

		player.magneticImpulse_timer = clamp(newMI);

	} else if(properties.gainDelay > 0.0f) {
		properties.gainDelay = 0.0f;
	}

	if(newFlyHoopSpeed < flyHoopSpeed && CurrentStage != DarkDesert){
		newFlyHoopSpeed = flyHoopSpeed;
	}

	if(MI::impulseData[player.index].magneticImpulse) {
		newFlyHoopSpeed += MI::calculateMultiplier(
				player, (newFlyHoopSpeed * 0.2f) * (player.magneticImpulse_timer / MI::MaximumCap));
	}

	player.speed = newFlyHoopSpeed;
}