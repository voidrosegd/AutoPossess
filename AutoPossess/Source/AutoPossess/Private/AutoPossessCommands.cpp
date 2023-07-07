/*
* AutoPossess - Unreal Engine 5 Plugin 
*
* Copyright (C) 2023 VOORHU <voorhu@gmail.com> All Rights Reserved.
*/

#include "AutoPossessCommands.h"

#define LOCTEXT_NAMESPACE "FAutoPossessModule"

void FAutoPossessCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "AutoPossess", "Crash is Coming! Bruh...", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
