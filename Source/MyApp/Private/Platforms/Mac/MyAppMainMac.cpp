// Copyright (c) 2026 Juan Marcelo Portillo

#include "MyAppMain.h"
#include "Mac/MacProgramDelegate.h"
#include "LaunchEngineLoop.h"

int main(int argc, char *argv[])
{
	return [MacProgramDelegate mainWithArgc:argc argv:argv programMain:UE::MyApp::Run programExit:FEngineLoop::AppExit];
}
