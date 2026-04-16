#include "ArrayFunc.h"

namespace ArrayFunctions {
	std::vector<int> generateArray(int size) {
		std::vector<int> arr;
		for (int i = 1; i < size + 1; i++) {
			arr.push_back(i);
		}
		shuffleArray(arr);
		return arr;
	}

	void shuffleArray(std::vector<int>& arr) {
		std::random_device rd;
		std::mt19937 g(rd());

		std::shuffle(arr.begin(), arr.end(), g);
	}

    std::vector<sf::RectangleShape> createVisualRects(const std::vector<int>& arr) {
        std::vector<sf::RectangleShape> output;
        if (arr.empty()) return output;

        float width = 1600.0f / arr.size();
        float maxHeight = 800.0f;
        int start = 160;

        for (size_t i = 0; i < arr.size(); i++) {

            float height = (arr[i] / (float)arr.size()) * maxHeight;

            sf::RectangleShape rect;

            rect.setSize({ width, height });
            rect.setOrigin({ 0, height });
            rect.setPosition({ start + i * width, 1000.0f });

            rect.setOutlineColor(sf::Color::Black);
            rect.setOutlineThickness(2);

            output.push_back(rect);
        }

        return output;
    }
    void updateVisualRects(const std::vector<int>& arr, std::vector<sf::RectangleShape>& rects, int &j) {

        if (arr.size() != rects.size()) return;
        

        float width = 1600.0f / arr.size();
        float maxHeight = 800.0f;

        float totalWidth = arr.size() * width;
        int start = 160;

        for (size_t i = 0; i < arr.size(); i++) {

            float height = (arr[i] / (float)arr.size()) * maxHeight;

            rects[i].setSize({ width, height });
            rects[i].setOrigin({ 0, height });
            rects[i].setPosition({ start + i * width, 1000.0f });
        }
        for (auto& rect : rects) {
            rect.setFillColor(sf::Color::White);
        }

        rects[j].setFillColor(sf::Color::Red);
    }
    void updateVisualRectsbogo(const std::vector<int>& arr, std::vector<sf::RectangleShape>& rects) {
        if (arr.empty()) return;

        float width = 1600.0f / arr.size();
        float maxHeight = 800.0f;
        float start = 160.0f;
        float baseY = 1000.0f;

        for (size_t i = 0; i < arr.size(); i++) {
            float height = (arr[i] / static_cast<float>(arr.size())) * maxHeight;

            rects[i].setSize({ width, height });
            rects[i].setOrigin({ 0.f, height });
            rects[i].setPosition({ start + i * width, baseY });

            rects[i].setOutlineColor(sf::Color::Black);
            rects[i].setOutlineThickness(2.f);
            rects[i].setFillColor(sf::Color::White);
        }
    }
}