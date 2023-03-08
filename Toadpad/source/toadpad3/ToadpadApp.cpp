#include "gui/toadpad3/ToadpadApp.h"

MushroomLib::ToadpadApp::ToadpadApp(const wchar_t* args, int showMode)
	: ApplicationBuilder(new MyApplication::TestWindow(), L"MushroomLib - Test application", showMode)
{
}