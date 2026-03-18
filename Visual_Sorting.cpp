#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

enum State {
	Menu,
	Bubble,
	Select,
	Insert,
	Bogo,
	Merge
};

int main() {
	unsigned int height = 1080;
	unsigned int width = 1920;
	unsigned int frames = 120;
	State currentState = State::Menu;
	int selectIndex = 0;
	float spacing = width / 6.0f;

	//Font
	sf::Font myFont;
	if (!myFont.openFromFile("assets/fonts/myFont.ttf")) {
		std::cerr << "Couldn't load assets/fonts/myFont.ttf" << std::endl;
	}

	//Menu
	sf::RectangleShape bubbleRect({ width / 7.0f , 120.0f }); //1
	bubbleRect.setOrigin({ width / 12.0f, 60.0f });
	bubbleRect.setPosition({ spacing * 1, (height / 3.0f) * 2 });
	bubbleRect.setOutlineThickness(5);

	sf::RectangleShape selectRect({ width / 7.0f , 120.0f }); //2
	selectRect.setOrigin({ width / 12.0f, 60.0f });
	selectRect.setPosition({ spacing * 2, (height / 3.0f) * 2 });
	selectRect.setOutlineThickness(5);

	sf::RectangleShape mergeRect({ width / 7.0f , 120.0f }); //3
	mergeRect.setOrigin({ width / 12.0f, 60.0f });
	mergeRect.setPosition({ spacing * 3, (height / 3.0f) * 2 });
	mergeRect.setOutlineThickness(5);

	sf::RectangleShape insertRect({ width / 7.0f , 120.0f }); //4
	insertRect.setOrigin({ width / 12.0f, 60.0f });
	insertRect.setPosition({ spacing * 4, (height / 3.0f) * 2 });
	insertRect.setOutlineThickness(5);

	sf::RectangleShape bogoRect({ width / 7.0f , 120.0f }); //5
	bogoRect.setOrigin({ width / 12.0f, 60.0f });
	bogoRect.setPosition({ spacing * 5, (height / 3.0f) * 2 });
	bogoRect.setOutlineThickness(5);

	std::vector<sf::RectangleShape*> menuRects = { &bubbleRect, &selectRect, &mergeRect, &insertRect, &bogoRect };

	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({ width, height  }), "Sorting Visualizer");
	window->setFramerateLimit(frames);

	while (window->isOpen()) {
		while (const std::optional event = window->pollEvent()) {

			if (event->is<sf::Event::Closed>()) {
				window->close();
			}

			if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {
				if (key->scancode == sf::Keyboard::Scancode::Left) {
					if (selectIndex > 0) {
						selectIndex--;
					}
				}
			}

			if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {
				if (key->scancode == sf::Keyboard::Scancode::Right) {
					if (selectIndex < 4) {
						selectIndex++;
					}
				}
			}

			else if (const auto* keypressed = event->getIf<sf::Event::KeyPressed>()) {
				if (keypressed->scancode == sf::Keyboard::Scancode::Escape) {
					window->close();
				}
			}
		}
		//running

		if (currentState == State::Menu) {
			for (int i = 0; i < menuRects.size(); i++) {
				if (i == selectIndex) {
					menuRects[i]->setOutlineColor(sf::Color::Blue);
				}
				else {
					menuRects[i]->setOutlineColor(sf::Color::White);
				}
			}
		}

		if (currentState == State::Bubble) {

		}

		//render
		window->clear(sf::Color::Black);

		if (currentState == State::Menu) {
			window->draw(bubbleRect);
			window->draw(insertRect);
			window->draw(bogoRect);
			window->draw(mergeRect);
			window->draw(selectRect);
		}

		if (currentState == State::Bubble) {

		}


		window->display();
	}
	delete window;
}