// Copyright Epic Games, Inc. All Rights Reserved.

#include "Test11GameMode.h"
#include "Test11Character.h"
#include "UObject/ConstructorHelpers.h"

ATest11GameMode::ATest11GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
