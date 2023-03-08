#pragma once

#include <stdexcept>
#include <vector>
#include <Windows.h>

namespace MushroomLib
{
	class Window;
	class EventDispatcher;

	/// <summary>
	/// The base class of all windows. Inherits from it if you want to created an extended event system for your windows.
	/// </summary>
	class AbstractWindow
	{
	private:
		EventDispatcher* m_EvListener = nullptr;

	protected:
		EventDispatcher* const addListener(EventDispatcher* base_or_derived);

		Window* m_Parent = nullptr;
		HWND m_Self = NULL;
		std::vector<Window*> m_Children;
		HFONT m_Font = NULL;
		HMENU m_Menu = NULL;
		DWORD m_Flags = 0U;
		DWORD m_ExFlags = 0U;
		bool m_Visible = false;

	public:
		AbstractWindow() = default;
		AbstractWindow(EventDispatcher* evDispatcher);

		AbstractWindow(AbstractWindow const&) = delete;
		const AbstractWindow& operator=(AbstractWindow const&) = delete;

		inline const HWND getHandle() const { return m_Self; }

		inline EventDispatcher* const getListener() const { return m_EvListener; }

		virtual ~AbstractWindow();
		virtual const wchar_t* getClass() = 0;
	};
}