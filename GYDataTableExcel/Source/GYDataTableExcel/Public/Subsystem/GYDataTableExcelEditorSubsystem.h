// Copyright 2024 GY. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "GYDataTableExcelEditorSubsystem.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class GYDATATABLEEXCEL_API UGYDataTableExcelEditorSubsystem : public UEditorSubsystem
{
	GENERATED_BODY()
	
public:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
};
