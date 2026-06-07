// Copyright (c) 2026 Juan Marcelo Portillo

#pragma once

#include "Templates/SharedPointer.h"

class FTabManager;

namespace UE::MyApp
{

class FMyAppToolset;

class IMyAppTool : public TSharedFromThis<IMyAppTool>
{
public:
	virtual void Initialize(const TSharedRef<FMyAppToolset>& InMyApp)
	{
	}

	struct FTabSpawnerContext
	{
		TSharedRef<FTabManager> TabManager;
	};
	/** Called to register all the tab spawners needed for the tool */
	virtual void RegisterTabSpawners(const FTabSpawnerContext& InContext)
	{
	}

	/** Called to unregister all the tab spawners that the tool registered */
	virtual void UnregisterTabSpawners(const FTabSpawnerContext& InContext)
	{
	}
};

} // UE::MyApp
