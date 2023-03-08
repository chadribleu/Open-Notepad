#include "gui/toadpad3/ApplicationBuilder.h"

MushroomLib::ApplicationBuilder::ApplicationBuilder(Window* window, const wchar_t* text, int show)
{
	m_Current = window;
	// set text and visibility
}

MushroomLib::ApplicationBuilder::~ApplicationBuilder()
{
	if (m_Current) {
		delete m_Current;
	}
}

int MushroomLib::ApplicationBuilder::run()
{
	if (!m_Current || !m_Current->getHandle()) {
		throw std::runtime_error("Error at: ApplicationBuilder::run()\nINVALID_HANDLE_OR_NULLPTR");
	}

	MSG currentMessage{ 0 };

	while (GetMessageW(&currentMessage, nullptr, NULL, NULL) > 0) {
		if (!TranslateAcceleratorW(this->getCurrent()->getHandle(), HACCEL(), &currentMessage)) {
			TranslateMessage(&currentMessage);
			DispatchMessageW(&currentMessage);
		}
	}

	return static_cast<int>(currentMessage.wParam);
}

const Clipboard* MushroomLib::ApplicationBuilder::getClipboard()
{
	return nullptr;
}

bool MushroomLib::ApplicationBuilder::enableCommonControls(ICCTYPE style)
{
	INITCOMMONCONTROLSEX iccex;
	iccex.dwSize = sizeof(iccex);
	iccex.dwICC = style;

	return static_cast<bool>(InitCommonControlsEx(&iccex));
}