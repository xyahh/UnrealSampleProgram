// Copyright (c) 2026 Juan Marcelo Portillo

#include "MyAppToolset.h"
#include "IMyAppTool.h"
#include "MyAppStyle.h"
#include "Sample/MyAppSampleTool.h"
#include "Styling/SlateStyleRegistry.h"
#include "Widgets/Docking/SDockTab.h"

#define LOCTEXT_NAMESPACE "MyAppToolset"

namespace UE::MyApp
{

void FMyAppToolset::Initialize()
{
	FSlateStyleRegistry::RegisterSlateStyle(FMyAppStyle::Get());

	MainTab = SNew(SDockTab);

	const TSharedRef<FGlobalTabmanager> GlobalTabManager = FGlobalTabmanager::Get();
	GlobalTabManager->SetApplicationTitle(LOCTEXT("AppTitle", "MyApp"));

	TabManager = GlobalTabManager->NewTabManager(MainTab.ToSharedRef());
	TabManager->SetCanDoDragOperation(false);

	RegisterTools();
	RegisterTabSpawners();
	LoadLayout();
}

void FMyAppToolset::Shutdown()
{
	UnregisterTabSpawners();

	FSlateStyleRegistry::UnRegisterSlateStyle(FMyAppStyle::Get());
	FMyAppStyle::TearDown();
}

void FMyAppToolset::RegisterTools()
{
	ON_SCOPE_EXIT
	{
		const TSharedRef<FMyAppToolset> This = SharedThis(this);
		for (const TSharedRef<IMyAppTool>& Tool : Tools)
		{
			Tool->Initialize(This);
		}
	};

	RegisterTool<FSampleTool>();
	// ... Register more tools here
}

void FMyAppToolset::LoadLayout()
{
	// Fill with tools' tab ids
	const TSharedRef<FTabManager::FLayout> Layout = FTabManager::NewLayout("MyAppLayout_V_0_1")
		->AddArea
		(
			FTabManager::NewArea(1230, 900)
			->Split
			(
				FTabManager::NewStack()
				->AddTab(FSampleTool::TabId, ETabState::OpenedTab)
			)
		);
	TabManager->RestoreFrom(Layout, nullptr);
}

void FMyAppToolset::RegisterTabSpawners()
{
	const IMyAppTool::FTabSpawnerContext SpawnerContext
		{
			.TabManager = TabManager.ToSharedRef()
		};
	for (const TSharedRef<IMyAppTool>& Tool : Tools)
	{
		Tool->RegisterTabSpawners(SpawnerContext);
	}
}

void FMyAppToolset::UnregisterTabSpawners()
{
	const IMyAppTool::FTabSpawnerContext SpawnerContext
		{
			.TabManager = TabManager.ToSharedRef()
		};
	for (const TSharedRef<IMyAppTool>& Tool : Tools)
	{
		Tool->UnregisterTabSpawners(SpawnerContext);
	}
}

} // UE::MyApp

#undef LOCTEXT_NAMESPACE
