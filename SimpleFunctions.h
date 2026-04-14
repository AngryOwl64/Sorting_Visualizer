#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

namespace simpleFuncs {
	void centerText(sf::Text& text);
	void drawRects(std::vector<sf::RectangleShape>& shapes, sf::RenderWindow& window);
	void drawTexts(std::vector<sf::Text>& texts, sf::RenderWindow& window);
}