// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GYDataTableExcel_Data.generated.h"

USTRUCT(BlueprintType)
struct FGY_DataTableExcelStruct
{
	GENERATED_USTRUCT_BODY()

	//导出去的表的名字
	//如果 Title = GY 那么导出的文件就是GY.csv和GY.xlsx
	//不用加文件后缀
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName Title;

	//表的描述
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Describe;

	//需要导入导出的表
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* DataTable;

	//文件导出路径，默认是.uproject为根
	//如果 ExcelPath = GY/Test ,那么导出路径就是 项目.uproject/GY/Test
	//路径推荐使用 /符号 来分割
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString ExcelPath;

};


/**
 * 
 */
UCLASS(Blueprintable)
class GYDATATABLEEXCEL_API UGYDataTableExcel_Data : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FGY_DataTableExcelStruct> DataTableExcels;

};
