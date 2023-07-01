// Copyright Epic Games, Inc. All Rights Reserved.

#include "AutoPossessStyle.h"
#include "AutoPossess.h"
#include "Framework/Application/SlateApplication.h"
#include "Styling/SlateStyleRegistry.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FAutoPossessStyle::StyleInstance = nullptr;

void FAutoPossessStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FAutoPossessStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FAutoPossessStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("AutoPossessStyle"));
	return StyleSetName;
}

const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);

TSharedRef< FSlateStyleSet > FAutoPossessStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("AutoPossessStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("AutoPossess")->GetBaseDir() / TEXT("Resources"));
	Style->Set("AutoPossess.PluginAction", new IMAGE_BRUSH(TEXT("cat1"), Icon16x16));

		/*FButtonStyle FlatButton = FButtonStyle()
		.SetNormal(IMAGE_BRUSH(TEXT("cat1"), Icon16x16))
		.SetHovered(IMAGE_BRUSH(TEXT("cat2"), Icon16x16))
		.SetPressed(IMAGE_BRUSH(TEXT("cat1"), Icon16x16, FLinearColor::Red))
		.SetNormalPadding(FMargin(1, 1, 1, 1))
		.SetPressedPadding(FMargin(1, 1, 1, 1));*/

	//Style->Set("AutoPossess.PluginAction", FButtonStyle(FlatButton));

	return Style;
}

void FAutoPossessStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FAutoPossessStyle::Get()
{
	return *StyleInstance;
}
