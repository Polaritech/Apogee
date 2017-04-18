#include "Win32Window.hpp"

using Win32Window = Apogee::Engine::UI::Win32Window;

auto Win32Window::SendMessages() -> bool {
	MSG msg = {};
	if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.message != WM_QUIT;
}

auto CALLBACK Win32Window::InitProc(HWND handle, UINT msg, WPARAM wParam, LPARAM lParam) -> LRESULT {
	if (msg == WM_NCCREATE) {
		LPCREATESTRUCT create = reinterpret_cast<LPCREATESTRUCT>(lParam);
		void* params = create->lpCreateParams;
		Win32Window* window = reinterpret_cast<Win32Window*>(params);
		SetWindowLongPtr(handle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(window));
		SetWindowLongPtr(handle, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(Win32Window::StaticProc));
		return window->MessageProc(handle, msg, wParam, lParam);
	}
	return DefWindowProc(handle, msg, wParam, lParam);
}

auto CALLBACK Win32Window::StaticProc(HWND handle, UINT msg, WPARAM wParam, LPARAM lParam) -> LRESULT {
	LONG_PTR raw = GetWindowLongPtr(handle, GWLP_USERDATA);
	Win32Window* window = reinterpret_cast<Win32Window*>(raw);
	if (window != nullptr) {
		return window->MessageProc(handle, msg, wParam, lParam);
	}
	else {
		return DefWindowProc(handle, msg, wParam, lParam);
	}
}

auto CALLBACK Win32Window::MessageProc(HWND handle, UINT msg, WPARAM wParam, LPARAM lParam) -> LRESULT {
	switch (msg) {
		case WM_DESTROY: {
			PostQuitMessage(0);
		} return 0;
	}
	return DefWindowProc(handle, msg, wParam, lParam);
}