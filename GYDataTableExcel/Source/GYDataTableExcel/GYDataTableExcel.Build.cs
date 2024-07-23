// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;
public class GYDataTableExcel : ModuleRules
{
	public GYDataTableExcel(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
				Path.Combine(ModuleDirectory, "Public"),
                Path.Combine(ModuleDirectory, "Public/EditorUtilityWidget"),
                Path.Combine(ModuleDirectory, "Public/Settings"),
                Path.Combine(ModuleDirectory, "Public/Data"),
                Path.Combine(ModuleDirectory, "Public/BlueprintFunctionLibrary"),
            }
            );
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Projects",
				"InputCore",
				"EditorFramework",
				"UnrealEd",
				"ToolMenus",
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
				"Blutility",
                "UMG",
                "DeveloperSettings",
                "EditorSubsystem",
                "UMGEditor",
                "EditorScriptingUtilities",
                "Slate",
                "ScriptableEditorWidgets",
            }
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
