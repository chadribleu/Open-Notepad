#pragma once

#include <Windows.h>
#include <CommCtrl.h>
#include <unordered_map>
#include <cstdlib>

#include <functional>

typedef std::function<LRESULT(WPARAM, LPARAM)> callback_func;
typedef LRESULT(*default_processing)(HWND, UINT, WPARAM, LPARAM);

namespace MushroomLib
{
	enum class Intent { SelfEventsProcessing, RegisterForSubclassing };

	class EventDispatcher
	{
	private:
		std::unordered_map<UINT, callback_func> m_EventsTable;
		MushroomLib::Intent m_Intent;

	protected:
		default_processing funPtr_defProcHandler;
		HWND m_Target;
		GUID m_uIdClass;
		virtual LRESULT handleMessage(UINT, WPARAM, LPARAM);
		bool m_InitializedFlag = false;

		EventDispatcher(MushroomLib::Intent subclassFlag);

	public:
		EventDispatcher(const EventDispatcher&) = delete;
		EventDispatcher& operator=(EventDispatcher const&) = delete;

		EventDispatcher();
		virtual ~EventDispatcher() = 0;

		void addHandler(UINT, callback_func);
		void removeHandler(UINT);

		inline HWND getAssociatedHandle() const { return m_Target; }
	};
}