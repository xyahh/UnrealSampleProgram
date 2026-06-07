// Copyright (c) 2026 Juan Marcelo Portillo

#include "MyAppStyle.h"
#include "Misc/LazySingleton.h"
#include "Styling/CoreStyle.h"
#include "Styling/SlateStyleMacros.h"

namespace UE::MyApp
{

FMyAppStyle& FMyAppStyle::Get()
{
	return TLazySingleton<FMyAppStyle>::Get();
}

void FMyAppStyle::TearDown()
{
	TLazySingleton<FMyAppStyle>::TearDown();
}

FMyAppStyle::FMyAppStyle()
	: FSlateStyleSet(TEXT("MyAppStyle"))
{
	ParentStyleName = FAppStyle::GetAppStyleSetName();
	ContentRootDir = FPaths::ProjectDir() / TEXT("Resources");
}

} // UE::MyApp
