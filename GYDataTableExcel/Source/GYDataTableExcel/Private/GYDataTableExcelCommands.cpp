// Copyright 2024 GY. All Rights Reserved.

#include "GYDataTableExcelCommands.h"

#define LOCTEXT_NAMESPACE "FGYDataTableExcelModule"

void FGYDataTableExcelCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "GYDataTableExcel", "Execute GYDataTableExcel action", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
