#include "Win32Window.hpp"

using Win32Window = Apogee::Engine::UI::Win32Window;

auto Win32Window::Width() const -> int {
	return m_Width;
}

auto Win32Window::Height() const -> int {
	return m_Height;
}

auto Win32Window::X() const -> int {
	return m_X;
}

auto Win32Window::Y() const -> int {
	return m_Y;
}

auto Win32Window::Title() const -> const std::string& {
	return m_Title;
}

auto Win32Window::Fullscreen() const -> bool {
	return m_Fullscreen;
}