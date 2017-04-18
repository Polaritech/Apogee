#include "Apogee/Engine/UI/Window.hpp"

int main(int argc, char** argv) {
	auto window = Apogee::Engine::UI::Window::Create();

	window->Width(1280);
	window->Height(720);
	window->Title("Apogee - The Best Engine Ever!");

	window->Show();

	while (window->SendMessages()) {
		// Do Some Stuff
	}
}