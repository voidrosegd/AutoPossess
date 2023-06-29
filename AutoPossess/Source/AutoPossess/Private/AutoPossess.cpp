// Copyright Epic Games, Inc. All Rights Reserved.

#include "AutoPossess.h"
#include "AutoPossessStyle.h"
#include "AutoPossessCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"

static const FName AutoPossessTabName("AutoPossess");

#define LOCTEXT_NAMESPACE "FAutoPossessModule"

void FAutoPossessModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FAutoPossessStyle::Initialize();
	FAutoPossessStyle::ReloadTextures();

	FAutoPossessCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FAutoPossessCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FAutoPossessModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FAutoPossessModule::RegisterMenus));
}

void FAutoPossessModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FAutoPossessStyle::Shutdown();

	FAutoPossessCommands::Unregister();
}

void FAutoPossessModule::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here
	FText DialogText = FText::Format(
							LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions"),
							FText::FromString(TEXT("FAutoPossessModule::PluginButtonClicked()")),
							FText::FromString(TEXT("AutoPossess.cpp"))
					   );
	FMessageDialog::Open(EAppMsgType::Ok, DialogText);
	/*
	* По клику делаем Possess в выделеного актора(если он павн и тп)
	* 
	* После вселения в выделеного актера, выселяемся из всех других(хотя думаю наоборот надо)
	*/

	//FLevelEditorModule& levelEditor = FModuleManager::GetModuleChecked(TEXT(“LevelEditor”));
	//levelEditor.OnActorSelectionChanged().AddUObject(this, &UElgEditorContext_LevelEditor::HandleOnActorSelectionChanged);

	// Take control of the default player
	//AutoPossessPlayer = EAutoReceiveInput::Player0;

	//TSubclassOf<AActor> ClassToFind; // Needs to be populated somehow (e.g. by exposing to blueprints as uproperty and setting it there
	//TArray<AActor*> FoundActors;
	//UGameplayStatics::GetAllActorsOfClass(GetWorld(), ClassToFind, FoundActors);

}

void FAutoPossessModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FAutoPossessCommands::Get().PluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FAutoPossessCommands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAutoPossessModule, AutoPossess)