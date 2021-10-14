#include "Screen.h"

int main(int argc, char* argv[])
{
	constexpr int width = 16 * 100;
	constexpr int height = 9 * 100;
	Screen<width, height> screen("My Application");

	auto pixels = std::vector<uint32_t>(width * height);

	bool is_running = true;
	while (is_running) {
		if (int event = screen.poll_events(); event == 1) {
			is_running = false;
		}
		std::fill(pixels.begin(), pixels.end(), 0);
        // fill pixels
		screen.update_texture(pixels);
	}
	return 0;
}
