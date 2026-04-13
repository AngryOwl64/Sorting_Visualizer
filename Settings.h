#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

namespace settings {
	void setfps(unsigned const int newFps, int& fps);
	std::vector<sf::RectangleShape> createSettingsRects();
	std::vector<sf::Text> createSettingsText();
	void runSettings(const auto& setting);
	void drawSettings(const auto& setting);
	void deleteSettings(const auto& setting);
}