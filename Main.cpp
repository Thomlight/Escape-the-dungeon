#include "Main.hpp"

int main() {
	
	RenderWindow window(VideoMode(1440, 1000), "Escape the Dungeon");
	Event event;

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}	
	}

	window.clear();
	window.display();
}