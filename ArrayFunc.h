#pragma once
#include <vector>
#include <random>
#include <algorithm>
#include "SFML/Graphics.hpp"

namespace ArrayFunctions {
	std::vector<int> generateArray(int size);
	void shuffleArray(std::vector<int>& arr);
	std::vector <sf::RectangleShape> createVisualRects(const std::vector<int>& arr);
	void updateVisualRects(const std::vector<int>& arr, std::vector<sf::RectangleShape>& rects, int& j);
}