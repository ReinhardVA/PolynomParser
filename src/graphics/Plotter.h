#pragma once
#include<vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

class Plotter
{
public:
	void drawGraph(const std::vector<sf::Vector2f>& points, sf::RenderWindow& window);
	void drawGrid(sf::RenderWindow& window);
	Plotter();
private:
	float zoom = 50.0f;
	sf::Vector2f origin;
	sf::Font m_font;
};

