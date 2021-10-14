
#include<chrono>
#include<iomanip>
#include<iostream>

#include "Screen.h"

uint64_t millis()
{
	uint64_t ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::
		now().time_since_epoch()).count();
	return ms;
}

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
		auto start = std::chrono::high_resolution_clock::now();
		/////////////////
		// fill pixels //
		/////////////////
		auto elapsed = std::chrono::high_resolution_clock::now() - start;
		if (auto t = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count(); t > 0) {
			int fps = 1000000 / t;
			std::cout << std::setw(4) << fps << " fps\r";
		}
		screen.update_texture(pixels);
	}
	return 0;
}
