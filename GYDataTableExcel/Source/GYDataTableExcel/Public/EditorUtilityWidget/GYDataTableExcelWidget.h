// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "GYDataTableExcelWidget.generated.h"


UCLASS()
class GYDATATABLEEXCEL_API UGYDataTableExcelWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UGYDataTableExcel_Data> DataTableExcel_Data;
	
	void InitDetails(TSubclassOf<class UGYDataTableExcel_Data> NewDataTableExcel_Data);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Editor")
	void InitDetailsBP(TSubclassOf<class UGYDataTableExcel_Data> NewDataTableExcel_Data);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UDetailsView* DataTableExcelDetails = nullptr;
};
