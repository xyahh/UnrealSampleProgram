// Copyright (c) 2026 Juan Marcelo Portillo

#pragma once

#include "Styling/SlateStyle.h"

namespace UE::MyApp
{

/** Style set to use for the app */
class FMyAppStyle : public FSlateStyleSet
{
public:
	static FMyAppStyle& Get();
	static void TearDown();

	FMyAppStyle();
};

} // UE::MyApp
