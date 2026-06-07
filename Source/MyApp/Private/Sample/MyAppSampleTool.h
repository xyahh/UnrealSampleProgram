// Copyright (c) 2026 Juan Marcelo Portillo

#pragma once

#include "IMyAppTool.h"
#include "UObject/NameTypes.h"

class FSpawnTabArgs;
class SDockTab;

namespace UE::MyApp
{

/** Sample tool to showing how IMyAppTools can be implemented */
class FSampleTool : public IMyAppTool
{
public:
	static const FLazyName TabId;

	//~ Begin IMyAppTool
	virtual void Initialize(const TSharedRef<FMyAppToolset>& InToolset) override;
	virtual void RegisterTabSpawners(const FTabSpawnerContext& InContext) override;
	virtual void UnregisterTabSpawners(const FTabSpawnerContext& InContext) override;
	//~ End IMyAppTool

private:
	TSharedRef<SDockTab> SpawnTab(const FSpawnTabArgs& InArgs);

	/** Owner of the tool */
	TWeakPtr<FMyAppToolset> ToolsetWeak;
};

} // UE::MyApp
