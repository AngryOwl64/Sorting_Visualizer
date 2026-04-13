#include "Settings.h"

namespace settings {
	void setfps(unsigned const int newFps, int& fps) {
		fps = newFps;
	}
	std::vector<sf::RectangleShape> createSettingsRects() {

		sf::RectangleShape fpsButton({ 150.0f, 70.0f });
		fpsButton.setOrigin({ 75.0f , 35.0f });
		fpsButton.setOutlineThickness(5);
		fpsButton.setPosition({ 300.0f, 590.0f });

		sf::RectangleShape backButton({ 150.0f, 70.0f });
		backButton.setOrigin({ 75.0f, 35.0f });
		backButton.setOutlineThickness(5);
		backButton.setPosition({ 300.0f, 830.0f });

		std::vector<sf::RectangleShape> shapes = {backButton, fpsButton};

		return shapes;
	}
	std::vector<sf::Text> createSettingsText() {
		sf::Font myFont;
		if (!myFont.openFromFile("assets/fonts/myFont.ttf")) {
			std::cerr << "Couldn't load assets/fonts/myFont.ttf" << std::endl;
		}

		sf::Text fpsText(myFont);
		fpsText.setString("change fps");
		fpsText.setCharacterSize(48);
		
		fpsText.setPosition({260.0f, 800.0f});
		fpsText.setFillColor(sf::Color::Black);

		std::vector<sf::Text> txts = {fpsText};
		return txts;
	}
}