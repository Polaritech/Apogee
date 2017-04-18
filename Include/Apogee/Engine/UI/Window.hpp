#pragma once

#include "Apogee/API.hpp"

#include <memory>
#include <string>

class RenderSurface;
class InputDevice;

namespace Apogee::Engine::UI {
	class Window {
	public:
		APOGEE_API Window() = default;
		APOGEE_API virtual ~Window() = default;

		APOGEE_API static auto Create() -> std::unique_ptr<Window>;

		APOGEE_API virtual auto Show() -> bool = 0;
		APOGEE_API virtual auto Hide() -> bool = 0;

		// Accessors
		APOGEE_API virtual auto Width() const -> int = 0;
		APOGEE_API virtual auto Height() const -> int = 0;
		APOGEE_API virtual auto X() const -> int = 0;
		APOGEE_API virtual auto Y() const -> int = 0;
		APOGEE_API virtual auto Title() const -> const std::string& = 0;
		APOGEE_API virtual auto Fullscreen() const -> bool = 0;

		// Modifiers
		APOGEE_API virtual auto Width(int width) -> bool = 0;
		APOGEE_API virtual auto Height(int height) -> bool = 0;
		APOGEE_API virtual auto X(int x) -> bool = 0;
		APOGEE_API virtual auto Y(int y) -> bool = 0;
		APOGEE_API virtual auto Title(const std::string& title) -> bool;
		APOGEE_API virtual auto Fullscreen(bool fullscreen) -> bool = 0;

		// Operating System Integration
		APOGEE_API virtual auto SendMessages() -> bool = 0;
	};
}