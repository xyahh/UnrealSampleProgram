// Copyright (c) 2026 Juan Marcelo Portillo

#pragma once

#include "Containers/Array.h"
#include "Templates/SharedPointer.h"

class FTabManager;
class SDockTab;

namespace UE::MyApp
{

class IMyAppTool;

/** Manages all the tools to use in the app */
class FMyAppToolset : public TSharedFromThis<FMyAppToolset>
{
public:
	void Initialize();
	void Shutdown();

	template<typename T> requires std::is_base_of_v<IMyAppTool, T>
	void RegisterTool()
	{
		Tools.Add(MakeShared<T>());
	}

private:
	void RegisterTools();
	void LoadLayout();

	void RegisterTabSpawners();
	void UnregisterTabSpawners();

	/** Main tab that owns the tab manager */
	TSharedPtr<SDockTab> MainTab;

	/** Tab manager to use for tools tabs */
	TSharedPtr<FTabManager> TabManager;

	/** All the registered tools */
	TArray<TSharedRef<IMyAppTool>> Tools;
};

} // UE::MyApp
