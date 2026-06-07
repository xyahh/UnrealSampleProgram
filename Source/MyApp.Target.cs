// Copyright (c) 2026 Juan Marcelo Portillo

using UnrealBuildTool;
using System.Collections.Generic;

public class MyAppTarget : TargetRules
{
	public MyAppTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Program;
		LinkType = TargetLinkType.Monolithic;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;

		LaunchModuleName = "MyApp";
		if (bBuildEditor)
		{
			ExtraModuleNames.Add("EditorStyle");
		}

		bCompileAgainstEngine = false;
		bCompileAgainstCoreUObject = true;
		bHasExports = false;
		bBuildDeveloperTools = true;
	}
}
