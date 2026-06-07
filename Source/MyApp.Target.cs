// Copyright (c) 2026 Juan Marcelo Portillo

using UnrealBuildTool;
using System.Collections.Generic;

public class MyAppTarget : TargetRules
{
	public MyAppTarget(TargetInfo Target) : base(Target)
	{
		// Equivalent of RunUAT.bat BuildPlugin -StrictIncludes
		// https://github.com/EpicGames/UnrealEngine/blob/5.5.0-release/Engine/Source/Programs/AutomationTool/Scripts/BuildPluginCommand.Automation.cs#L122-L126
		bUseUnityBuild = false;
		bUsePCHFiles = false;
		bUseSharedPCHs = false;

		Type = TargetType.Program;
		LinkType = TargetLinkType.Monolithic;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;

		LaunchModuleName = "MyApp";
		if (bBuildEditor)
		{
			ExtraModuleNames.Add("EditorStyle");
		}

		// MyApp doesn't ever compile with the engine linked in
		bCompileAgainstEngine = false;

		// We need CoreUObject compiled in as the source code access module requires it
		bCompileAgainstCoreUObject = true;

		// MyApp.exe has no exports, so no need to verify that a .lib and .exp file was emitted by
		// the linker.
		bHasExports = false;

		// Make sure to get all code in SlateEditorStyle compiled in
		bBuildDeveloperTools = true;
	}
}
