// Copyright (c) 2026 Juan Marcelo Portillo

using System.IO;
using UnrealBuildTool;

public class MyApp : ModuleRules
{
	public MyApp(ReadOnlyTargetRules Target) : base(Target)
	{
		PublicIncludePathModuleNames.AddRange(
			new string[] {
				"Launch",
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[] {
				"AppFramework",
				"ApplicationCore",
				"Core",
				"Projects",
				"Slate",
				"SlateCore",
				"StandaloneRenderer",
			}
		);

		if (Target.IsInPlatformGroup(UnrealPlatformGroup.Linux))
		{
			PrivateDependencyModuleNames.AddRange(
				new string[] {
					"UnixCommonStartup",
				}
			);
		}
	}
}
