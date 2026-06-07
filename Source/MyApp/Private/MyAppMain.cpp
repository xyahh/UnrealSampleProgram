// Copyright (c) 2026 Juan Marcelo Portillo

#include "MyAppMain.h"
#include "Framework/Application/SlateApplication.h"
#include "Framework/Docking/TabManager.h"
#include "Modules/ModuleManager.h"
#include "RequiredProgramMainCPPInclude.h"
#include "StandaloneRenderer.h"
#include "MyAppStyle.h"
#include "MyAppToolset.h"
#include "Styling/StarshipCoreStyle.h"

IMPLEMENT_APPLICATION(MyApp, "MyApp");

#define LOCTEXT_NAMESPACE "MyAppMain"

namespace UE::MyApp
{

int32 Run(const TCHAR* InCommandLine)
{
	FTaskTagScope TaskTagScope(ETaskTag::EGameThread);

	// start up the main loop
	GEngineLoop.PreInit(InCommandLine);

	// Make sure all UObject classes are registered and default properties have been initialized
	ProcessNewlyLoadedUObjects();

	// Tell the module manager it may now process newly loaded UObjects when new C++ modules are loaded
	FModuleManager::Get().StartProcessingNewlyLoadedObjects();

	// crank up a normal Slate application using the platform's standalone renderer
	FSlateApplication::InitializeAsStandaloneApplication(GetStandardStandaloneRenderer());
	FSlateApplication::InitHighDPI(true);
	FAppStyle::SetAppStyleSetName(FMyAppStyle::Get().GetStyleSetName());

	{
		TSharedRef<UE::MyApp::FMyAppToolset> Toolset = MakeShared<UE::MyApp::FMyAppToolset>();
		Toolset->Initialize();
		ON_SCOPE_EXIT
		{
			Toolset->Shutdown();
		};

		// loop while the server does the rest
		while (!IsEngineExitRequested())
		{
			BeginExitIfRequested();

			FTaskGraphInterface::Get().ProcessThreadUntilIdle(ENamedThreads::GameThread);
			UE::Stats::FStats::AdvanceFrame(false);
			FTSTicker::GetCoreTicker().Tick(FApp::GetDeltaTime());
			FSlateApplication::Get().PumpMessages();
			FSlateApplication::Get().Tick();
			FPlatformProcess::Sleep(0.01);
			GFrameCounter++;
		}
	}

	FCoreDelegates::OnExit.Broadcast();
	FSlateApplication::Shutdown();

	FModuleManager::Get().UnloadModulesAtShutdown();

	GEngineLoop.AppPreExit();
	GEngineLoop.AppExit();
	return 0;
}

} // UE::MyApp

#undef LOCTEXT_NAMESPACE
