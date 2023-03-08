#pragma once

#include "SubclassedLoopHandler.h"
#include "LoopHandler.h"

#include <Windows.h>

namespace MushroomLib
{
	namespace OS
	{
		class MushroomLib::Window;

		static bool registerWindowClass(Window* _template)
		{
			WNDCLASSEXW wcex{ 0 };
			wcex.cbSize = sizeof(WNDCLASSEX);
			wcex.lpszClassName = _template->getClass();
			wcex.lpfnWndProc = LoopHandler::getMainProcedurePtr();
			wcex.hInstance = GetModuleHandleW(NULL);
			wcex.hbrBackground = static_cast<HBRUSH>(GetStockObject(GRAY_BRUSH));
			wcex.hCursor = LoadCursorW(NULL, IDC_ARROW);
			
			if (RegisterClassExW(&wcex)) {
				return true;
			}
			return false;
		}
	}
}