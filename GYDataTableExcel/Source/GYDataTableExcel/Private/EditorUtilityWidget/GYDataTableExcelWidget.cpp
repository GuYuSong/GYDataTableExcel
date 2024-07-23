// Fill out your copyright notice in the Description page of Project Settings.


#include "GYDataTableExcelWidget.h"
#include "Editor/ScriptableEditorWidgets/Public/Components/DetailsView.h"
#include "Data/GYDataTableExcel_Data.h"


void UGYDataTableExcelWidget::InitDetails(TSubclassOf<class UGYDataTableExcel_Data> NewDataTableExcel_Data)
{
	if (!NewDataTableExcel_Data)
	{
		return;
	}

	if (!DataTableExcelDetails)
	{
		return;
	}

	DataTableExcel_Data = NewDataTableExcel_Data;
	
	DataTableExcelDetails->SetObject(DataTableExcel_Data->GetDefaultObject());

	InitDetailsBP(DataTableExcel_Data);
}
