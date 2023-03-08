// -------------------------------------------------------------------------------------------
// Toadpad 2.0 entry point - See other files for more information
// -------------------------------------------------------------------------------------------

// TOADPAD 3
#include "gui/toadpad3/ToadpadApp.h"

int WINAPI wWinMain(HINSTANCE hInst, HINSTANCE UNREFERENCED_PARAMETER(hPrevInstance), LPWSTR pCmdLine, int nCmdShow) 
{
	MushroomLib::ApplicationBuilder::enableCommonControls(ICCStyle::STANDARD | ICCStyle::WIN95STD);
	MushroomLib::ToadpadApp myApp(pCmdLine, nCmdShow);
	return myApp.run();
}