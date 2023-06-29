// Copyright Epic Games, Inc. All Rights Reserved.

#include "AutoPossessCommands.h"

#define LOCTEXT_NAMESPACE "FAutoPossessModule"

void FAutoPossessCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "AutoPossess", "Execute AutoPossess action", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
