#pragma once

#include "ApplicationBuilder.h"
#include "TestWindow.h"

namespace MushroomLib
{
	class ToadpadApp : public ApplicationBuilder
	{
	public:
		ToadpadApp(const wchar_t* args, int showMode);
	};
}