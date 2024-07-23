// Fill out your copyright notice in the Description page of Project Settings.

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
