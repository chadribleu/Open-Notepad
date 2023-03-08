#include "Button.h"

MushroomLib::Button::Button(Window* parent)
	: Window(parent, WS_VISIBLE)
{
	// todo: rewrite initialize (not optimal)
	if (!this->initialize(parent, WS_VISIBLE, m_ExFlags)) {
		throw std::exception("Bad info, can't register window");
	}
}

// add events
MushroomLib::Button::~Button()
{
}

void MushroomLib::OnClickListener::onClick(Window* view) 
{
}

void MushroomLib::OnClickListener::onDoubleClick(Window* view)
{
}

void MushroomLib::OnClickListener::onRelease(Window* view)
{
}
