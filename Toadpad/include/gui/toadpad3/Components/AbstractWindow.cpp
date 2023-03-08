#include "AbstractWindow.h"

MushroomLib::AbstractWindow::AbstractWindow(EventDispatcher* evDispatcher)
	: m_EvListener(evDispatcher)
{
}

MushroomLib::AbstractWindow::~AbstractWindow()
{
	if (m_EvListener) {
		delete m_EvListener;
	}
}

MushroomLib::EventDispatcher* const MushroomLib::AbstractWindow::addListener(EventDispatcher* base_or_derived)
{
	if (m_EvListener && m_EvListener != base_or_derived) {
		delete m_EvListener;
	}
	m_EvListener = base_or_derived;
	return m_EvListener;
}