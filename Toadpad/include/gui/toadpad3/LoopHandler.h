#pragma once

#include <Windows.h>
#include "EventDispatcher.h"

namespace MushroomLib
{
	/// <summary>
	/// Inherits from EventDispatcher, wrapper for listening to newly-created window's events
	/// </summary>
	class LoopHandler : public EventDispatcher
	{
	private:
		static LRESULT CALLBACK internalProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	public:
		LoopHandler(LoopHandler const&) = delete;
		LoopHandler& operator=(LoopHandler const&) = delete;

		LoopHandler();
		virtual ~LoopHandler() {}

		/// <summary>
		/// Returns a pointer to a procedure that can be used to listen to intercept messages
		/// </summary>
		static WNDPROC getMainProcedurePtr() { return LoopHandler::internalProc; }
	};
}