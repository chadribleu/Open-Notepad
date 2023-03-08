#pragma once

#include "utils/clipboard.h"
#include "LoopHandler.h"
#include <stdexcept>

#include "Components/Window.h"

namespace MushroomLib
{
	using ICCTYPE = int;
	namespace ICCStyle
	{
		static inline constexpr int ANIMATE = ICC_ANIMATE_CLASS;
		static inline constexpr int BAR = ICC_BAR_CLASSES;
		static inline constexpr int REBAR = ICC_COOL_CLASSES;
		static inline constexpr int DATE = ICC_DATE_CLASSES;
		static inline constexpr int HOTKEY = ICC_HOTKEY_CLASS;
		static inline constexpr int IPADDRESS = ICC_INTERNET_CLASSES;
		static inline constexpr int HYPERLINKCTL = ICC_LINK_CLASS;
		static inline constexpr int LISTVIEW = ICC_LISTVIEW_CLASSES;
		static inline constexpr int NATIVEFNTCTL = ICC_NATIVEFNTCTL_CLASS;
		static inline constexpr int PAGESCROLLER = ICC_PAGESCROLLER_CLASS;
		static inline constexpr int PROGRESSBAR = ICC_PROGRESS_CLASS;
		static inline constexpr int TABCTL = ICC_TAB_CLASSES;
		static inline constexpr int TREEVIEW = ICC_TREEVIEW_CLASSES;
		static inline constexpr int UPDOWNCTL = ICC_UPDOWN_CLASS;
		static inline constexpr int COMBOBOXEX = ICC_USEREX_CLASSES;
		static inline constexpr int WIN95STD = ICC_WIN95_CLASSES;
		static inline constexpr int STANDARD = ICC_STANDARD_CLASSES;
	}

	class ApplicationBuilder
	{
	private:
		Window* m_Current = nullptr;
	
	protected:
		HINSTANCE m_PreviousInstance = NULL;
		HINSTANCE m_CurrentInstance = NULL;

	public:
		ApplicationBuilder() = default;
		ApplicationBuilder(Window* window, const wchar_t* text, int show);
		virtual ~ApplicationBuilder() = 0;

		ApplicationBuilder(const ApplicationBuilder&) = delete;
		const ApplicationBuilder& operator=(const ApplicationBuilder&) = delete;

		virtual int run() final;

		inline const Window* getCurrent() { return m_Current; }

		static const Clipboard* getClipboard();
		static bool enableCommonControls(ICCTYPE style);
		static inline HINSTANCE getCurrentInstance(ApplicationBuilder& app) 
		{
			if (!app.m_CurrentInstance) {
				app.m_CurrentInstance = GetModuleHandle(NULL);
			}
			return app.m_CurrentInstance;
		}
	};
}