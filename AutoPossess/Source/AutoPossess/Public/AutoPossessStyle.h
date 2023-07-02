/*
* AutoPossess - Unreal Engine 5 Advertise Plugin for Yandex
*
* Copyright (C) 2023 VOORHU <voorhu@gmail.com> All Rights Reserved.
*/
#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateStyle.h"

class FAutoPossessStyle
{
public:

	static void Initialize();

	static void Shutdown();

	/** reloads textures used by slate renderer */
	static void ReloadTextures();

	/** @return The Slate style set for the Shooter game */
	static const ISlateStyle& Get();

	static FName GetStyleSetName();

private:

	static TSharedRef< class FSlateStyleSet > Create();

private:

	static TSharedPtr< class FSlateStyleSet > StyleInstance;
};