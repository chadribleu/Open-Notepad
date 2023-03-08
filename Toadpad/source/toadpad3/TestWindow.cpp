#include "gui/toadpad3/TestWindow.h"
#include <functional>

MyApplication::TestWindow::TestWindow()
	: Window(nullptr, WS_OVERLAPPEDWINDOW | WS_VISIBLE)
{
	WNDCLASSEX classInfo{ 0 };
	if (!GetClassInfoExW(GetModuleHandleW(NULL), this->getClass(), &classInfo)) {
		if (!MushroomLib::OS::registerWindowClass(this)) {
			throw std::runtime_error("Unable to register the window class!");
		}
	}
	this->addListener(new MushroomLib::LoopHandler());

	// you must register WM_CREATE before initializing the window if you want to listen to this message
	this->getListener()->addHandler(WM_CREATE, std::bind(&TestWindow::onCreate, this, std::placeholders::_1, std::placeholders::_2));

	this->getListener()->addHandler(WM_SIZE, [](WPARAM, LPARAM) -> LRESULT {
		return S_OK;
	});
	this->getListener()->addHandler(WM_DESTROY, std::bind(&TestWindow::onDestroy, this, std::placeholders::_1, std::placeholders::_2));

	//initialize the window
	if (!this->initialize(nullptr, WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0)) {
		throw std::runtime_error("MushroomLib - Couldn't initialize Window::base_or_derived");
	}

	// register other events such as WM_SIZE or WM_PAINT...
}

LRESULT MyApplication::TestWindow::onCreate(WPARAM wParam, LPARAM lParam)
{
	MessageBox(this->getHandle(), this->getClass(), L"MushroomLib - Sample MessageBox", MB_OK);
	m_Button = new MushroomLib::Button(this);
	m_Button->getListener()->addHandler(WM_COMMAND, [](WPARAM wParam, LPARAM lParam) -> LRESULT {
			MessageBox(NULL, L"Clicked", L"Hello", MB_OK);
			return S_OK;
	});
	return S_OK;
}

LRESULT MyApplication::TestWindow::onDestroy(WPARAM wParam, LPARAM lParam)
{
	MessageBox(this->getHandle(), L"Click OK to close the process.", L"MushroomLib - Sample MessageBox", MB_OK);
	PostQuitMessage(0);
	return S_OK;
}
