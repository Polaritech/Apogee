#include "Win32Window.hpp"

using Win32Window = Apogee::Engine::UI::Win32Window;

auto Win32Window::Terminate() -> bool {
	if (m_Handle != nullptr) {
		DestroyWindow(m_Handle);
		m_Handle = nullptr;
	}
	return true;
}