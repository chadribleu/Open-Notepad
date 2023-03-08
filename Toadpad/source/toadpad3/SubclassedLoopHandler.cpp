#include "gui/toadpad3/SubclassedLoopHandler.h"

LRESULT MushroomLib::SubclassedLoopHandler::internalSubclassedProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, 
    UINT_PTR uIdSubclass, DWORD_PTR dwRefData)
{
    if (hWnd == NULL) {
        return 0;
    }

    SubclassedLoopHandler* pThis = reinterpret_cast<SubclassedLoopHandler*>(dwRefData);
    if (pThis) {
        return pThis->handleMessage(uMsg, wParam, lParam);
    }
    return DefSubclassProc(hWnd, uMsg, wParam, lParam);
}

MushroomLib::SubclassedLoopHandler::SubclassedLoopHandler(MushroomLib::Window* target)
    : EventDispatcher(MushroomLib::Intent::RegisterForSubclassing)
{
    m_Target = target->getHandle();
    funPtr_defProcHandler = DefSubclassProc;
    SetWindowSubclass(m_Target, SubclassedLoopHandler::internalSubclassedProc, 
        m_uIdClass.Data1, reinterpret_cast<LONG_PTR>(this));
}