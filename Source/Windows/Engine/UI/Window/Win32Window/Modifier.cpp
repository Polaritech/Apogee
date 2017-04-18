#include "Win32Window.hpp"

using Win32Window = Apogee::Engine::UI::Win32Window;

auto Win32Window::Width(int width) -> bool {
	m_Width = width;
	return true;
}

auto Win32Window::Height(int height) -> bool {
	m_Height = height;
	return true;
}

auto Win32Window::X(int x) -> bool {
	m_X = x;
	return true;
}

auto Win32Window::Y(int y) -> bool {
	m_Y = y;
	return true;
}

auto Win32Window::Title(const std::string& title) -> bool {
	m_Title = title;
	return true;
}

auto Win32Window::Fullscreen(bool fullscreen) -> bool {
	m_Fullscreen = fullscreen;
	return true;
}