#include "Apogee/Engine/UI/Window.hpp"
#include "Win32Window/Win32Window.hpp"

using Window = Apogee::Engine::UI::Window;
using Win32Window = Apogee::Engine::UI::Win32Window;

auto Window::Create() -> std::unique_ptr<Window> {
	return std::make_unique<Win32Window>();
}