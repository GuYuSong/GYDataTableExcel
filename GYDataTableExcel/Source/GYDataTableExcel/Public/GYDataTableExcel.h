// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FToolBarBuilder;
class FMenuBuilder;

class FGYDataTableExcelModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	/** This function will be bound to Command. */
	void PluginButtonClicked();
	
private:

	void RegisterMenus();

	void CreateDataTableExcelSettings();
	void DeleteDataTableExcelSettings();

	class UGYDataTableExcelSettings* DataTableExcelSettings = nullptr;
private:
	TSharedPtr<class FUICommandList> PluginCommands;
};
