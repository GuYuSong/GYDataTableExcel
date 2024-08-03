// Copyright 2024 GY. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "GYDataTableExcelStyle.h"

class FGYDataTableExcelCommands : public TCommands<FGYDataTableExcelCommands>
{
public:

	FGYDataTableExcelCommands()
		: TCommands<FGYDataTableExcelCommands>(TEXT("GYDataTableExcel"), NSLOCTEXT("Contexts", "GYDataTableExcel", "GYDataTableExcel Plugin"), NAME_None, FGYDataTableExcelStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
