#include "Settings.h"

void centerText(sf::Text& text) {
	sf::FloatRect bounds = text.getLocalBounds();
	text.setOrigin({
		bounds.position.x + bounds.size.x / 2.f,
		bounds.position.y + bounds.size.y / 2.f
		});
}

namespace settings {
	void setfps(unsigned const int newFps, sf::RenderWindow* window) {
		window->setFramerateLimit(newFps);
	}
	std::vector<sf::RectangleShape> createSettingsRects() {

		sf::RectangleShape fpsButton15({ 200.0f, 100.0f });
		fpsButton15.setOrigin({ 100.0f , 50.0f });
		fpsButton15.setOutlineThickness(5);
		fpsButton15.setPosition({ 250.0f, 300.0f });

		sf::RectangleShape fpsButton30({ 200.0f, 100.0f });
		fpsButton30.setOrigin({ 100.0f , 50.0f });
		fpsButton30.setOutlineThickness(5);
		fpsButton30.setPosition({ 500.0f, 300.0f });

		sf::RectangleShape fpsButton60({ 200.0f, 100.0f });
		fpsButton60.setOrigin({ 100.0f , 50.0f });
		fpsButton60.setOutlineThickness(5);
		fpsButton60.setPosition({ 750.0f, 300.0f });

		sf::RectangleShape fpsButton120({ 200.0f, 100.0f });
		fpsButton120.setOrigin({ 100.0f , 50.0f });
		fpsButton120.setOutlineThickness(5);
		fpsButton120.setPosition({ 1000.0f, 300.0f });

		sf::RectangleShape fpsButton240({ 200.0f, 100.0f });
		fpsButton240.setOrigin({ 100.0f , 50.0f });
		fpsButton240.setOutlineThickness(5);
		fpsButton240.setPosition({ 1250.0f, 300.0f });

		sf::RectangleShape backButton({ 150.0f, 70.0f });
		backButton.setOrigin({ 75.0f, 35.0f });
		backButton.setOutlineThickness(5);
		backButton.setPosition({ 150.0f, 830.0f });

		std::vector<sf::RectangleShape> shapes = {backButton, fpsButton15, fpsButton30, fpsButton60, fpsButton120, fpsButton240};

		return shapes;
	}
	std::vector<sf::Text> createSettingsText() {
		static sf::Font myFont;
		if (!myFont.openFromFile("assets/fonts/myFont.ttf")) {
			std::cerr << "Couldn't load assets/fonts/myFont.ttf" << std::endl;
		}

		sf::Text title(myFont);
		title.setString("Choose the FPS");
		title.setCharacterSize(96);
		title.setPosition({ 100.0f, 50.0f });
			
		sf::Text fpsText15(myFont);
		fpsText15.setString("15");
		fpsText15.setCharacterSize(48);
		centerText(fpsText15);
		fpsText15.setPosition({ 250.0f, 300.0f });
		fpsText15.setFillColor(sf::Color::Black);

		sf::Text fpsText30(myFont);
		fpsText30.setString("30");
		fpsText30.setCharacterSize(48);
		centerText(fpsText30);
		fpsText30.setPosition({ 500.0f, 300.0f });
		fpsText30.setFillColor(sf::Color::Black);

		sf::Text fpsText60(myFont);
		fpsText60.setString("60");
		fpsText60.setCharacterSize(48);
		centerText(fpsText60);
		fpsText60.setPosition({ 750.0f, 300.0f });
		fpsText60.setFillColor(sf::Color::Black);

		sf::Text fpsText120(myFont);
		fpsText120.setString("120");
		fpsText120.setCharacterSize(48);
		centerText(fpsText120);
		fpsText120.setPosition({ 1000.0f, 300.0f });
		fpsText120.setFillColor(sf::Color::Black);

		sf::Text fpsText240(myFont);
		fpsText240.setString("240");
		fpsText240.setCharacterSize(48);
		centerText(fpsText240);
		fpsText240.setPosition({ 1250.0f, 300.0f });
		fpsText240.setFillColor(sf::Color::Black);

		std::vector<sf::Text> txts = {title, fpsText15, fpsText30, fpsText60, fpsText120, fpsText240};
		return txts;
	}
}