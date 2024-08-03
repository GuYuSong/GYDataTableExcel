// Copyright 2024 GY. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "Engine/DeveloperSettings.h"
#include "Data/GYDataTableExcel_Data.h"
#include "GYDataTableExcelSettings.generated.h"

/**
 * 
 */
UCLASS(config = Editor, defaultconfig)
class GYDATATABLEEXCEL_API UGYDataTableExcelSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:

	//UPROPERTY(config, EditAnywhere, Category = "Buttons")
	//TSubclassOf<UWidgetBlueprint> GYDataTableExcelWidgetBP;

	UPROPERTY(config, EditAnywhere, BlueprintReadWrite, Category = "DataTableExcelSettings")
	FString BP_GYDataTableExcelWidgetPath = "/Script/Blutility.EditorUtilityWidgetBlueprint'/GYDataTableExcel/EditorUtilityWidget/EUW_GYDataTableExcelWidget.EUW_GYDataTableExcelWidget'";

	UPROPERTY(config, EditAnywhere, BlueprintReadWrite, Category = "DataTableExcelSettings")
	TSubclassOf<class UGYDataTableExcel_Data> GYDataTableExcel_Data = UGYDataTableExcel_Data::StaticClass();

	virtual FName GetCategoryName() const override;

};
