/*
* AutoPossess - Unreal Engine 5 Plugin 
*
* Copyright (C) 2023 VOORHU <voorhu@gmail.com> All Rights Reserved.
*/

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
	TSubclassOf<AActor> ClassToFind;
	TArray<AActor*> FoundActors;
	FWorldContext* world = GEngine->GetWorldContextFromGameViewport(GEngine->GameViewport);
	world->World()->GetActorCount();

	UGameplayStatics::GetAllActorsOfClass(world->World(), ClassToFind, FoundActors);//world->World()  u->GetWorld()

	TArray<AActor*> findActors = world->World()->GetCurrentLevel()->Actors;
	for (int i = 0; i < findActors.Num(); i++) {
		if (world->World()->ContainsActor(findActors[i])) {
			if (findActors[i]->IsSelectedInEditor()) {
				APawn* papa = Cast<APawn>(findActors[i]);
				if (papa != nullptr) {
					papa->AutoPossessPlayer = EAutoReceiveInput::Player0;
					SET_WARN_COLOR(COLOR_BLACK);
					UE_LOG(Voorhu, Warning, TEXT("Possess of %s set to Player0"), *findActors[i]->GetActorLabel());
					CLEAR_WARN_COLOR();
				}
				else
					UE_LOG(Voorhu, Error, TEXT("%s not valid,\nCareful, all Actor's Possess is set Disable!"), *findActors[i]->GetActorLabel());
			}
			else {
				//UE_LOG(Voorhu, Warning, TEXT("%s is not selected"), *findActors[i]->GetActorLabel());
				APawn* mama = Cast<APawn>(findActors[i]);
				if (mama != nullptr) mama->AutoPossessPlayer = EAutoReceiveInput::Disabled;
				//UE_LOG(Voorhu, Warning, TEXT("%s is selected"), *findActors[i]->GetActorLabel());
			}
		}
		else {
			//UE_LOG(Voorhu, Error, TEXT("not find"));
		}

	}
	GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Blue, FString::Printf(TEXT("length of findActors = %d"), findActors.Num()));
	//GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Blue, FString::Printf(TEXT("length of FoundActors = %d"), FoundActors.Num()));
	GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Blue, FString::Printf(TEXT("worldName = %s"), *world->World()->GetDebugDisplayName()));
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