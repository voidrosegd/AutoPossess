/*
* AutoPossess - Unreal Engine 5 Plugin 
*
* Copyright (C) 2023 VOORHU <voorhu@gmail.com> All Rights Reserved.
*/

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "AutoPossessStyle.h"

class FAutoPossessCommands : public TCommands<FAutoPossessCommands>
{
public:

	FAutoPossessCommands():TCommands<FAutoPossessCommands>(TEXT("AutoPossess"), NSLOCTEXT("Contexts", "AutoPossess", "AutoPossess Plugin"), NAME_None, FAutoPossessStyle::GetStyleSetName())
	{

	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
