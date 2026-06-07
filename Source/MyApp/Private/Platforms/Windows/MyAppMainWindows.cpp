// Copyright (c) 2026 Juan Marcelo Portillo

#include "MyAppMain.h"
#include "Windows/WindowsHWrapper.h"

/** WinMain, called when the application is started */
int WINAPI WinMain(_In_ HINSTANCE hInInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR, _In_ int nCmdShow)
{
	UE::MyApp::Run(GetCommandLineW());
	return 0;
}
