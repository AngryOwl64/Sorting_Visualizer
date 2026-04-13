#include <SFML/Window.hpp>
#include "Algorithms.h"
#include "ArrayFunc.h"

enum State {
	Menu,
	Elements,
	Settings,
	Sort
};
enum Algorithm {
	Bubble,
	Select,
	Merge,
	Insert,
	Bogo
};

void centerText(sf::Text& text) {
	sf::FloatRect bounds = text.getLocalBounds();

	text.setOrigin({
		bounds.position.x + bounds.size.x / 2.f,
		bounds.position.y + bounds.size.y / 2.f
	});
}

int main() {
	unsigned int frames = 30;
	unsigned int height = 1080;
	unsigned int width = 1920;
	int selectIndex = 0;
	float spacing = width / 6.0f;

	State currentState = State::Menu;
	Algorithm selectedAlgorithm;
	std::vector<int> valueArray;
	std::vector<sf::RectangleShape> visualArray;
	int i = 0; int j = 0; bool finished = false;

	std::vector<Algorithm> algos = {
	Algorithm::Bubble,
	Algorithm::Select,
	Algorithm::Merge,
	Algorithm::Insert,
	Algorithm::Bogo
	};

	//Font
	sf::Font myFont;
	if (!myFont.openFromFile("assets/fonts/myFont.ttf")) {
		std::cerr << "Couldn't load assets/fonts/myFont.ttf" << std::endl;
	}

	sf::FloatRect tempRect;

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

	sf::RectangleShape optionRect({ width / 7.0f, 120.0f });
	optionRect.setOrigin({ width / 12.0f, 60.0f });
	optionRect.setPosition({ 1750.0f, 930.0f });
	optionRect.setOutlineThickness(5);

	sf::Text title(myFont);
	title.setString("SORTING ALGORITHM Visualizer"); //17 = 7
	title.setCharacterSize(75);
	centerText(title);
	title.setPosition({ width / 2.0f, 200 });

	sf::Text bubbleText(myFont);
	bubbleText.setString("Bubble-Sort");
	bubbleText.setCharacterSize(48);
	centerText(bubbleText);
	bubbleText.setPosition({ spacing * 0.93f , (height / 3.0f) * 2 });
	bubbleText.setFillColor(sf::Color::Black);

	sf::Text selectText(myFont);
	selectText.setString("Selection-Sort");
	selectText.setCharacterSize(48);
	centerText(selectText);
	selectText.setPosition({ spacing * 1.93f, (height / 3.0f) * 2 });
	selectText.setFillColor(sf::Color::Black);

	sf::Text mergeText(myFont);
	mergeText.setString("Merge-Sort");
	mergeText.setCharacterSize(48);
	centerText(mergeText);
	mergeText.setPosition({ spacing * 2.93f, (height / 3.0f) * 2 });
	mergeText.setFillColor(sf::Color::Black);

	sf::Text insertText(myFont);
	insertText.setString("Insert-Sort");
	insertText.setCharacterSize(48);
	centerText(insertText);
	insertText.setPosition({ spacing * 3.93f, (height / 3.0f) * 2 });
	insertText.setFillColor(sf::Color::Black);

	sf::Text bogoText(myFont);
	bogoText.setString("Bogo-Sort");
	bogoText.setCharacterSize(48);
	centerText(bogoText);
	bogoText.setPosition({ spacing * 4.93f, (height / 3.0f) * 2 });
	bogoText.setFillColor(sf::Color::Black);

	sf::Text optionText(myFont);
	optionText.setString("options");
	optionText.setCharacterSize(48);
	centerText(optionText);
	optionText.setPosition({ 1730.0f, 930.0f });
	optionText.setFillColor(sf::Color::Black);

	std::vector<sf::RectangleShape> menuRects = { bubbleRect, selectRect, mergeRect, insertRect, bogoRect, optionRect };
	std::vector<sf::Text> menuText = { title, bubbleText, selectText, mergeText, insertText, bogoText, optionText};

	//Elements
	sf::Text titleElements(myFont);
	titleElements.setCharacterSize(96);
	titleElements.setString("Enter the Number of Elements you want sorted:");
	centerText(titleElements);
	titleElements.setPosition({ width / 2.0f, height / 3.0f });
	titleElements.setFillColor(sf::Color::White);

	sf::RectangleShape inputBox({ 500.f, 100.f });
	inputBox.setOrigin({250, 50});
	inputBox.setPosition({ width / 2.0f, height / 2.0f });

	sf::Text inputText(myFont);
	inputText.setCharacterSize(96);
	inputText.setPosition({ (width / 2.0f)-250, (height / 2.0f) - 60 }); 
	inputText.setFillColor(sf::Color::Blue);

	std::string inputString;

	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({ width, height  }), "Sorting Visualizer");
	window->setFramerateLimit(frames);

	while (window->isOpen()) {
		while (const std::optional event = window->pollEvent()) {

			if (event->is<sf::Event::Closed>()) {
				window->close();
			}

			if (currentState == State::Menu) {
				//std::cerr << "Menu\n";
				if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {
					switch (key->scancode) {
					case sf::Keyboard::Scancode::Left:
						if (selectIndex > 0) { selectIndex--; break; }
						else if (selectIndex == 0) selectIndex = 4; break;

					case sf::Keyboard::Scancode::Right:
						std::cout << selectIndex << std::endl;
						if (selectIndex < 5) { selectIndex++; break; }
						else if (selectIndex == 5) selectIndex = 0; break;

					case sf::Keyboard::Scancode::Enter:
						currentState = State::Elements; break;
						std::cout << "enter\n";

					case sf::Keyboard::Scancode::Escape:
						window->close();
						break;
					default: break;
					}
				}
			}

			if (currentState == State::Elements) {
				std::cerr << "Elements\n";
				if (const auto* textEntered = event->getIf<sf::Event::TextEntered>()) {
					if (textEntered->unicode == 8) { // Backspace
						if (!inputString.empty())
							inputString.pop_back();
					}
					else if (textEntered->unicode < 128) {
						char c = static_cast<char>(textEntered->unicode);
						if (std::isdigit(c) && inputString.size() < 10) {
							inputString += c;
						}
					}
					inputText.setString(inputString);
				}

				else if (const auto* keypressed = event->getIf<sf::Event::KeyPressed>()) {
					if (keypressed->scancode == sf::Keyboard::Scancode::Enter && !inputString.empty() && std::stoi(inputString) > 1) {
						selectedAlgorithm = algos[selectIndex];
						currentState = State::Sort;
						valueArray = ArrayFunctions::generateArray(std::stoi(inputString));
						visualArray = ArrayFunctions::createVisualRects(valueArray);
					}
				}
			}
		}

		//running
		if (currentState == State::Menu) {
			for (int i = 0; i < menuRects.size(); i++) {
				if (i == selectIndex) {
					menuRects[i].setOutlineColor(sf::Color::Blue);
				}
				else {
					menuRects[i].setOutlineColor(sf::Color::White);
				}
			}
		}

		//render
		window->clear(sf::Color::Black);

		if (currentState == State::Menu) {
			for (sf::RectangleShape rect : menuRects) {
				window->draw(rect);
			}
			for (sf::Text text : menuText) {
				window->draw(text);
			}
		}

		if (currentState == State::Elements) {
			window->draw(inputBox);
			window->draw(inputText);
			window->draw(titleElements);
		}

		if (currentState == State::Sort) {
			switch (selectedAlgorithm)
			{
			case Bubble: 
				SortingAlgorithms::bubbleSortStep(valueArray, i, j, finished);
				if (!finished) {
					ArrayFunctions::updateVisualRects(valueArray, visualArray, j);
				} else {
					for (auto& rect : visualArray) {
						rect.setFillColor(sf::Color::Green);
					}
				}
				for (size_t i = 0; i < valueArray.size(); i++) {
					//std::cerr << valueArray[i] << " ";
					window->draw(visualArray[i]);
				} break;
			case Select:
				break;
			case Merge:
				break;
			case Insert:
				break;
			case Bogo:
				break;
			default:
				break;
			}
			if (finished) {
				
			}
		}
		window->display();
	}
	delete window;
}