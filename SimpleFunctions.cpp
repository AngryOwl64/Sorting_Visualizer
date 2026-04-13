#include "SimpleFunctions.h"

namespace simpleFuncs {
	void centerText(sf::Text& text) {
		sf::FloatRect bounds = text.getLocalBounds();
		text.setOrigin({
			bounds.position.x + bounds.size.x / 2.f,
			bounds.position.y + bounds.size.y / 2.f
			});
	}
}