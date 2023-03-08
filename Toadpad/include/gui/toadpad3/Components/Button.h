#pragma once

#include "Window.h"

namespace MushroomLib
{
	class OnClickListener 
	{
	public:
		void onClick(Window* view);
		void onDoubleClick(Window* view);
		void onRelease(Window* view);
	};

	class Button : public Window
	{
	private:
		OnClickListener m_ClickListenerHandler;

	public:
		Button(const Button&) = delete;
		Button& operator=(const Button&) = delete;

		Button(Window* parent);
		virtual ~Button();

		inline void setOnClickEventListener(OnClickListener listener) 
		{
			m_ClickListenerHandler = listener;
		}

		const wchar_t* getClass() { return L"BUTTON"; }
	};
}