/*
* ADSCore Lite - Unreal Engine 5 Advertise Plugin for Yandex
*
* Copyright (C) 2023 VOORHU <voorhu@gmail.com> All Rights Reserved.
*/

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "LevelEditor.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"

#include "CustomLogCategory.h"



class FToolBarBuilder;
class FMenuBuilder;

class FAutoPossessModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	/** This function will be bound to Command. */
	void PluginButtonClicked();
	
private:

	void RegisterMenus();


private:
	TSharedPtr<class FUICommandList> PluginCommands;
};
