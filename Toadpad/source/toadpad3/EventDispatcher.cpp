#include "gui/toadpad3/EventDispatcher.h"

namespace MushroomLib
{
    LRESULT EventDispatcher::handleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        std::unordered_map<UINT, callback_func>::iterator it = m_EventsTable.find(uMsg);
        if (it == m_EventsTable.end()) {
            return funPtr_defProcHandler(this->m_Target, uMsg, wParam, lParam);
        }
        return it->second(wParam, lParam);
    }

    /// <summary>
    /// You must implement the Intent argument.
    /// </summary>
    EventDispatcher::EventDispatcher(MushroomLib::Intent intent)
        : m_Target(NULL), m_Intent(intent), m_InitializedFlag(true), funPtr_defProcHandler(DefSubclassProc)
    {
        if (UuidCreate(&m_uIdClass) != RPC_S_OK) {
            throw std::exception("Unable to generate a GUID for the requested EventHandler");
        }
    }

    EventDispatcher::EventDispatcher()
        : m_Target(NULL), m_Intent(MushroomLib::Intent::RegisterForSubclassing), m_InitializedFlag(true),
        funPtr_defProcHandler(DefSubclassProc)
    {
        if (UuidCreate(&m_uIdClass) != RPC_S_OK) {
            throw std::exception("Unable to generate a GUID for the requested EventHandler");
        }
    }

    EventDispatcher::~EventDispatcher()
    {
    }

    void EventDispatcher::addHandler(UINT uMsg, callback_func callback)
    {
        m_EventsTable.insert(std::make_pair(uMsg, callback));
    }

    void EventDispatcher::removeHandler(UINT uMsg)
    {
        m_EventsTable.erase(uMsg);
    }
}