
#include<chrono>
#include<iomanip>

#include "Screen.h"

uint64_t millis()
{
	uint64_t ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::
		now().time_since_epoch()).count();
	return ms;
}

void render_scene(std::vector<uint32_t>& pixels, int width, int height)
{
	auto start = std::chrono::high_resolution_clock::now();
	std::fill(pixels.begin(), pixels.end(), 0);
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			// do stuff
		}
	}
	auto elapsed = std::chrono::high_resolution_clock::now() - start;
	if (auto t = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count(); t > 0) {
		int fps = 1000000 / t;
		std::cout << std::setw(4) << fps << " fps\r";
	}
}

int main(int argc, char* argv[])
{
	constexpr int width = 16 * 100;
	constexpr int height = 9 * 100;
	Screen<width, height> screen("My Window");

	auto pixels = std::vector<uint32_t>(width * height);

	bool is_running = true;
	while (is_running) {
		if (int event = screen.poll_events(); event == 1) {
			is_running = false;
		}
		render_scene(pixels, width, height);
		screen.update_texture(pixels);
	}
	return 0;
}
