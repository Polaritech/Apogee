#include "Win32Window.hpp"

using Win32Window = Apogee::Engine::UI::Win32Window;

auto Win32Window::Initialize() -> bool {
	m_App = GetModuleHandle(nullptr);

	WNDCLASSEX wndClass = {};
	if (GetClassInfoEx(m_App, "Apogee_WindowClass", &wndClass) == 0) {
		LPTSTR defaultCursor = reinterpret_cast<TCHAR*>(32512);
		int defaultColor = 6;

		wndClass.cbSize = sizeof(WNDCLASSEX);
		wndClass.hbrBackground = reinterpret_cast<HBRUSH>(defaultColor);
		wndClass.hCursor = LoadCursor(nullptr, defaultCursor);
		wndClass.hIcon = LoadCursor(nullptr, defaultCursor);
		wndClass.hIconSm = LoadCursor(nullptr, defaultCursor);
		wndClass.hInstance = m_App;
		wndClass.lpfnWndProc = Win32Window::InitProc;
		wndClass.lpszClassName = "Apogee_WindowClass";
		wndClass.style = CS_HREDRAW | CS_VREDRAW;

		if (!RegisterClassEx(&wndClass)) {
			//DWORD error = GetLastError();
			return false;
		}
	}

	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	if (m_Width == -1 || m_Width > screenWidth) {
		m_Width = screenWidth;
	}
	if (m_Height == -1 || m_Height > screenHeight) {
		m_Height = screenHeight;
	}
	if (m_X == -1) {
		m_X = (screenWidth - m_Width) / 2;
	}
	if (m_Y == -1) {
		m_Y = (screenHeight - m_Height) / 2;
	}
	if (m_Title.empty()) {
		m_Title = "Apogee Window";
	}

	m_Handle = CreateWindowEx(0, wndClass.lpszClassName, m_Title.c_str(),
							  WS_OVERLAPPEDWINDOW, m_X, m_Y, m_Width, m_Height,
							  nullptr, nullptr, m_App, this);

	if (m_Handle == nullptr) {
		return false;
	}

	return true;
}