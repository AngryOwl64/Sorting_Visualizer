#include "SimpleFunctions.h"

namespace simpleFuncs {
	void centerText(sf::Text& text) {
		sf::FloatRect bounds = text.getLocalBounds();
		text.setOrigin({
			bounds.position.x + bounds.size.x / 2.f,
			bounds.position.y + bounds.size.y / 2.f
			});
	}
	void drawRects(std::vector<sf::RectangleShape> &shapes, sf::RenderWindow &window) {
		for (const auto& shape : shapes) {
			window.draw(shape);
		}
	}
	void drawTexts(std::vector<sf::Text>& texts, sf::RenderWindow& window) {
		for (const auto& text : texts) {
			window.draw(text);
		}
	}
	void resetValues(std::vector<sf::RectangleShape>& rectArr, std::vector<int>& intArr,
		int& i, int& j, bool& isfinished) {
		rectArr.clear();
		intArr.clear();
		isfinished = false;
		i = 0;
		j = 0;
	}
}