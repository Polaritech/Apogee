#include "Win32Window.hpp"

using Win32Window = Apogee::Engine::UI::Win32Window;

Win32Window::Win32Window() : m_Width(-1), m_Height(-1), m_X(-1), m_Y(-1),
							 m_Fullscreen(false), m_Title() {}

Win32Window::~Win32Window() {
	this->Terminate();
}