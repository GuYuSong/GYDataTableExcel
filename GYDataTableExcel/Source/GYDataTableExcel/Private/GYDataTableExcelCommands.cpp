// Copyright Epic Games, Inc. All Rights Reserved.

#include "GYDataTableExcelCommands.h"

#define LOCTEXT_NAMESPACE "FGYDataTableExcelModule"

void FGYDataTableExcelCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "GYDataTableExcel", "Execute GYDataTableExcel action", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
