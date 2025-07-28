#pragma once

#include "riders/character.hpp"
#include "riders/player.hpp"

constexpr std::array<CharacterArchetype, Character::Total> AllCharacterArchetypes = {
		CharacterArchetype::LateBooster, // sonic
		CharacterArchetype::Combat, // tails
		CharacterArchetype::Combat, // knuckles
		CharacterArchetype::Drift, // amy
		CharacterArchetype::TopSpeed, // jet
		CharacterArchetype::TopSpeed, // storm
		CharacterArchetype::LateBooster, // wave
		CharacterArchetype::AllRounder, // eggman
		CharacterArchetype::AllRounder, // cream
		CharacterArchetype::Collector, // rouge
		CharacterArchetype::Combat, // shadow
		CharacterArchetype::SuperSonic, // super sonic
		CharacterArchetype::TopSpeed, // nights
		CharacterArchetype::LateBooster, // aiai
		CharacterArchetype::AllRounder, // ulala
		CharacterArchetype::NoType, // e10g
		CharacterArchetype::Drift, // e10b/e10r
		CharacterArchetype::Trickster, // silver
		CharacterArchetype::Collector, // metal sonic
		CharacterArchetype::AllRounder, // emerl
		CharacterArchetype::Trickster, // blaze
		CharacterArchetype::Collector, // chaos
		CharacterArchetype::Trickster, // tikal
};

ASMUsed void Player_CharacterArchetype(Player *player);