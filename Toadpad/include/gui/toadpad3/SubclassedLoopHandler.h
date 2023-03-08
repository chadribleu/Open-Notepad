#pragma once

#include "EventDispatcher.h"
#include "Components/Window.h"

namespace MushroomLib
{
	class SubclassedLoopHandler : public EventDispatcher
	{
	private:
		static LRESULT CALLBACK internalSubclassedProc(HWND, UINT, WPARAM, LPARAM, UINT_PTR, DWORD_PTR);

	public:
		SubclassedLoopHandler() = delete;
		SubclassedLoopHandler(const SubclassedLoopHandler&) = delete;

		SubclassedLoopHandler(Window* target);
		~SubclassedLoopHandler() {}

		const SubclassedLoopHandler& operator=(const SubclassedLoopHandler&) = delete;
	};
}