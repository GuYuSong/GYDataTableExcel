// Copyright 2024 GY. All Rights Reserved.

#include "GYDataTableExcel.h"
#include "GYDataTableExcelStyle.h"
#include "GYDataTableExcelCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"
#include "Settings/GYDataTableExcelSettings.h"
#include "Editor/Blutility/Public/EditorUtilityLibrary.h"
#include "GYDataTableExcelWidget.h"
#include "Subsystem/GYDataTableExcelEditorSubsystem.h"
#include "EditorAssetLibrary.h"
#include "Editor/UMGEditor/Public/WidgetBlueprint.h"
#include "Editor/Blutility/Classes/EditorUtilityWidgetBlueprint.h"
#include "Editor/Blutility/Public/EditorUtilitySubsystem.h"

static const FName GYDataTableExcelTabName("GYDataTableExcel");

#define LOCTEXT_NAMESPACE "FGYDataTableExcelModule"

void FGYDataTableExcelModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FGYDataTableExcelStyle::Initialize();
	FGYDataTableExcelStyle::ReloadTextures();

	FGYDataTableExcelCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FGYDataTableExcelCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FGYDataTableExcelModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FGYDataTableExcelModule::RegisterMenus));

	CreateDataTableExcelSettings();
}

void FGYDataTableExcelModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FGYDataTableExcelStyle::Shutdown();

	FGYDataTableExcelCommands::Unregister();

	DeleteDataTableExcelSettings();
}

void FGYDataTableExcelModule::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here
	//FText DialogText = FText::Format(
	//						LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions"),
	//						FText::FromString(TEXT("FGYDataTableExcelModule::PluginButtonClicked()")),
	//						FText::FromString(TEXT("GYDataTableExcel.cpp"))
	//				   );
	//FMessageDialog::Open(EAppMsgType::Ok, DialogText);
	//

	if (DataTableExcelSettings)
	{
		UEditorUtilityWidgetBlueprint* DataTableExcelWidget = Cast<UEditorUtilityWidgetBlueprint>(UEditorAssetLibrary::LoadAsset(DataTableExcelSettings->BP_GYDataTableExcelWidgetPath));
		if (DataTableExcelWidget)
		{
			if (GEditor)
			{
				UEditorUtilitySubsystem* EUSubsystem = GEditor->GetEditorSubsystem<UEditorUtilitySubsystem>();
				if (EUSubsystem)
				{
					UGYDataTableExcelWidget* DataTableExcelWidgetIns = Cast<UGYDataTableExcelWidget>(EUSubsystem->SpawnAndRegisterTab(DataTableExcelWidget));
					if (DataTableExcelWidgetIns)
					{
						DataTableExcelWidgetIns->InitDetails(DataTableExcelSettings->GYDataTableExcel_Data);
					}
				}
			}
		}
	}
}

void FGYDataTableExcelModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FGYDataTableExcelCommands::Get().PluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FGYDataTableExcelCommands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}


void FGYDataTableExcelModule::CreateDataTableExcelSettings()
{
	DataTableExcelSettings = NewObject<UGYDataTableExcelSettings>(GetTransientPackage(), UGYDataTableExcelSettings::StaticClass());
	check(DataTableExcelSettings);
	DataTableExcelSettings->AddToRoot();
}


void FGYDataTableExcelModule::DeleteDataTableExcelSettings()
{
	if (!GExitPurge) // If GExitPurge Object is already gone
	{
		DataTableExcelSettings->RemoveFromRoot();
	}
	DataTableExcelSettings = nullptr;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FGYDataTableExcelModule, GYDataTableExcel)