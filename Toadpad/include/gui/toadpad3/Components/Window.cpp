#include "Window.h"
#include "gui/toadpad3/OS.h"

MushroomLib::Window::Window(Window* parent, DWORD flags, DWORD exFlags)
	: AbstractWindow()
{
}

bool MushroomLib::Window::initialize(Window* parent, DWORD flags, DWORD exFlags)
{
	return this->initialize(parent, flags, exFlags, this->getListener());
}

bool MushroomLib::Window::initialize(Window* parent, DWORD flags, DWORD exFlags, EventDispatcher* eventListener)
{
	m_Flags = flags;
	m_ExFlags = exFlags;

	bool isChild = false;
	if (parent != nullptr) {
		isChild = true;
		
		m_Parent = parent;
		auto pOther = m_Parent->getListener()->getAssociatedHandle();

		m_Flags |= WS_CHILD;
	}

	// getAssociatedHandle: ensure that the parent of a child window will always returns a valid handle.
	m_Self = CreateWindowExW(m_ExFlags, this->getClass(), L"MushroomLib - Empty application", m_Flags,
		CW_USEDEFAULT, CW_USEDEFAULT, 300, 300, isChild ? m_Parent->getListener()->getAssociatedHandle() : nullptr, NULL,
		GetModuleHandleW(NULL), !isChild ? this->getListener() : nullptr);

	if (isChild) {
		this->addListener(new SubclassedLoopHandler(this)); // add listener after the window was created.
	}

	auto handle_to_window = m_Self;
	auto error = GetLastError();

	return (m_Self ? true : false);
}