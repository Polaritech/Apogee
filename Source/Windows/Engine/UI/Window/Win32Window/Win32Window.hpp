#pragma once

#include "Apogee/Engine/UI/Window.hpp"

#include <Windows.h>

namespace Apogee::Engine::UI {
	class Win32Window : public virtual Window {
	public:
		Win32Window();
		~Win32Window();

		auto Show() -> bool override;
		auto Hide() -> bool override;

		auto Initialize() -> bool;
		auto Terminate() -> bool;

		// Accessors
		auto Width() const -> int override;
		auto Height() const -> int override;
		auto X() const -> int override;
		auto Y() const -> int override;
		auto Title() const -> const std::string& override;
		auto Fullscreen() const -> bool override;

		// Modifiers
		auto Width(int width) -> bool override;
		auto Height(int height) -> bool override;
		auto X(int x) -> bool override;
		auto Y(int y) -> bool override;
		auto Title(const std::string& title) -> bool override;
		auto Fullscreen(bool fullscreen) -> bool override;

		// Operating System Integration
		auto SendMessages() -> bool override;
		static auto CALLBACK InitProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) -> LRESULT;
		static auto CALLBACK StaticProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) -> LRESULT;
		auto CALLBACK MessageProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) -> LRESULT;

	private:
		bool m_Initialized;

		int m_Width;
		int m_Height;
		int m_X;
		int m_Y;
		bool m_Fullscreen;

		std::string m_Title;

		HWND m_Handle;
		HINSTANCE m_App;
		bool m_Visible;
	};
}