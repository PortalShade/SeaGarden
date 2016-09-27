// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "SeaForest.h"
#include "SeaForestGameMode.h"
#include "SeaForestHUD.h"
#include "SeaForestCharacter.h"

ASeaForestGameMode::ASeaForestGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ASeaForestHUD::StaticClass();
}
