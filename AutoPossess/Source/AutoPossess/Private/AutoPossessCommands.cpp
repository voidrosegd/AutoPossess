// Copyright Epic Games, Inc. All Rights Reserved.

#include "AutoPossessCommands.h"

#define LOCTEXT_NAMESPACE "FAutoPossessModule"

void FAutoPossessCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "AutoPossess", "Crash is Coming! Bruh...", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
