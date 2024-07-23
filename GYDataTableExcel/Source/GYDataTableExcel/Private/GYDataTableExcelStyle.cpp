// Copyright Epic Games, Inc. All Rights Reserved.

#include "GYDataTableExcelStyle.h"
#include "GYDataTableExcel.h"
#include "Framework/Application/SlateApplication.h"
#include "Styling/SlateStyleRegistry.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FGYDataTableExcelStyle::StyleInstance = nullptr;

void FGYDataTableExcelStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FGYDataTableExcelStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FGYDataTableExcelStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("GYDataTableExcelStyle"));
	return StyleSetName;
}


const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);

TSharedRef< FSlateStyleSet > FGYDataTableExcelStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("GYDataTableExcelStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("GYDataTableExcel")->GetBaseDir() / TEXT("Resources"));

	Style->Set("GYDataTableExcel.PluginAction", new IMAGE_BRUSH(TEXT("Icon/Icon20"), Icon20x20));
	return Style;
}

void FGYDataTableExcelStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FGYDataTableExcelStyle::Get()
{
	return *StyleInstance;
}
