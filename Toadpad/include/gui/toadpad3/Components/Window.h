#pragma once

#include "AbstractWindow.h"

namespace MushroomLib
{
	class EventDispatcher;
	class LoopHandler;
	class SubclassedLoopHandler;

	class Window : public AbstractWindow
	{
	private:

	protected:
		bool initialize(Window* parent, DWORD flags, DWORD exFlags);
		bool initialize(Window* parent, DWORD flags, DWORD exFlags, EventDispatcher* eventListener);

	public:
		Window(Window* parent, DWORD flags = WS_OVERLAPPEDWINDOW, DWORD exFlags = 0U);
		virtual const wchar_t* getClass() override { return L"Toadpad.Window"; }
	};
}