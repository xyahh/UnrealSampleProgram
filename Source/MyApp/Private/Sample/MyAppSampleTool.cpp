// Copyright (c) 2026 Juan Marcelo Portillo

#include "MyAppSampleTool.h"
#include "Framework/Docking/TabManager.h"
#include "MyAppStyle.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "MyAppSampleTool"

namespace UE::MyApp
{

const FLazyName FSampleTool::TabId("Sample");

void FSampleTool::Initialize(const TSharedRef<FMyAppToolset>& InToolset)
{
	ToolsetWeak = InToolset;
}

void FSampleTool::RegisterTabSpawners(const FTabSpawnerContext& InContext)
{
	InContext.TabManager->RegisterTabSpawner(TabId, FOnSpawnTab::CreateSP(this, &FSampleTool::SpawnTab))
		.SetDisplayName(LOCTEXT("TabTitle", "Sample"));
}

void FSampleTool::UnregisterTabSpawners(const FTabSpawnerContext& InContext)
{
	InContext.TabManager->UnregisterTabSpawner(TabId);
}

TSharedRef<SDockTab> FSampleTool::SpawnTab(const FSpawnTabArgs& InArgs)
{
	return SNew(SDockTab)
		.TabRole(MajorTab)
		[
			SNew(SBox)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("SampleText", "This is a sample text from UE::MyApp::FSampleTool"))
			]
		];
}

} // UE::MyApp

#undef LOCTEXT_NAMESPACE
