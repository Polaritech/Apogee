#include "Win32Window.hpp"

using Win32Window = Apogee::Engine::UI::Win32Window;

auto Win32Window::Show() -> bool {
	if (!m_Visible) {
		bool status = true;
		if (!m_Initialized) {
			status = this->Initialize();
			if (!status) return false;
		}

		ShowWindow(m_Handle, SW_SHOW);
	}
	return true;
}

auto Win32Window::Hide() -> bool {
	if (m_Visible) {
		ShowWindow(m_Handle, SW_SHOW);
	}
	return false;
}