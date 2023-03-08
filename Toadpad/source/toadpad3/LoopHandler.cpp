#include "gui/toadpad3/LoopHandler.h"

/// <summary>
/// This function redirects all messages to handleMessage. Use EventDispatcher if you want to listen to the ones of an already-existing window.
/// </summary>
LRESULT MushroomLib::LoopHandler::internalProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (hWnd == NULL) {
		return 0;
	}

	LoopHandler* pThis = nullptr;
	if (uMsg == WM_NCCREATE) {
		pThis = static_cast<LoopHandler*>(reinterpret_cast<LPCREATESTRUCT>(lParam)->lpCreateParams);
		SetWindowLongPtrW(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pThis));
		pThis->m_Target = hWnd;
	}
	else {
		pThis = reinterpret_cast<LoopHandler*>(GetWindowLongPtrW(hWnd, GWLP_USERDATA));
	}
	if (pThis) {
		return pThis->handleMessage(uMsg, wParam, lParam);
	}
	return DefWindowProcW(hWnd, uMsg, wParam, lParam);
}

MushroomLib::LoopHandler::LoopHandler()
	: EventDispatcher(MushroomLib::Intent::SelfEventsProcessing)
{
	funPtr_defProcHandler = DefWindowProcW;
}