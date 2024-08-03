// Copyright 2024 GY. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "GYDataTableExcelWidget.generated.h"


UCLASS()
class GYDATATABLEEXCEL_API UGYDataTableExcelWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataTableExcelWidget")
	TSubclassOf<class UGYDataTableExcel_Data> DataTableExcel_Data;
	
	void InitDetails(TSubclassOf<class UGYDataTableExcel_Data> NewDataTableExcel_Data);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "DataTableExcelWidget")
	void InitDetailsBP(TSubclassOf<class UGYDataTableExcel_Data> NewDataTableExcel_Data);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget), Category = "DataTableExcelWidget")
	class UDetailsView* DataTableExcelDetails = nullptr;
};
