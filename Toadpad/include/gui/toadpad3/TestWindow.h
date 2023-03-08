#pragma once

#include "OS.h"
#include "Components/Window.h"
#include "Components/Button.h"

namespace MyApplication
{
	class TestWindow : public MushroomLib::Window
	{
	private:
		MushroomLib::Button* m_Button = nullptr;

	public:
		TestWindow();
		TestWindow(const MushroomLib::Window&) = delete;
		const wchar_t* getClass() override { return L"Toadpad"; }

		LRESULT onCreate(WPARAM wParam, LPARAM lParam);
		LRESULT onDestroy(WPARAM wParam, LPARAM lParam);
	};
}