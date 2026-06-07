// Copyright (c) 2026 Juan Marcelo Portillo

#include "MyAppMain.h"
#include "UnixCommonStartup.h"

int main(int argc, char *argv[])
{
	return CommonUnixMain(argc, argv, &UE::MyApp::Run);
}
