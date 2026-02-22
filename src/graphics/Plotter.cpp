#include "Plotter.h"
#include <iostream>

void Plotter::drawGraph(const std::vector<sf::Vector2f>& points, sf::RenderWindow& window)
{
	if (points.empty()) return;
	sf::VertexArray graph(sf::PrimitiveType::LineStrip);
	graph.resize(points.size());
	for (size_t i = 0; i < points.size(); i++) {
		sf::Vector2f graphPoint = points[i];
		graphPoint.x = origin.x + (graphPoint.x * zoom);
		graphPoint.y = origin.y - (graphPoint.y * zoom);
		graph[i] = sf::Vertex(graphPoint, sf::Color::Red);
	}
	window.draw(graph);
}

void Plotter::drawGrid(sf::RenderWindow& window)
{
	sf::Vector2u size = window.getSize();
	float width = static_cast<float>(size.x);
	float height = static_cast<float>(size.y);
	sf::Text text(m_font);

	text.setCharacterSize(12);
	text.setFillColor(sf::Color::White);

	origin = { width / 2.0f, height / 2.0f }; // 400, 300
	
	sf::VertexArray gridLines(sf::PrimitiveType::Lines);

	sf::Color gridColor(50, 50, 50);
	sf::Color axisColor(200, 200, 200); 

	int minX = static_cast<int>(-(origin.x) / zoom) - 1; // -400 / 50 = -8 - 1 = -9
	int maxX = static_cast<int>((width - origin.x) / zoom) + 1; // ((800 - 400) / 50) + 1 = 8 + 1 = 9
	int minY = static_cast<int>(-(height - origin.y) / zoom) - 1;
	int maxY = static_cast<int>(origin.y / zoom) + 1;

	for (int i = minX; i <= maxX; i++) {
		float screenX = origin.x + (i * zoom);

		sf::Color lineColor = (i == 0) ? axisColor : gridColor;
		
		// Dikey çizgiler
		gridLines.append(sf::Vertex(sf::Vector2f(screenX, 0.f), lineColor));
		gridLines.append(sf::Vertex(sf::Vector2f(screenX, height), lineColor));
		if (i != 0) {
			text.setString(std::to_string(i));
			text.setPosition({ screenX, origin.y + 2.f });
			window.draw(text); 
		}
	}

	for(int i = minY; i <= maxY; i++){
		
		float screenY = origin.y - (i * zoom);
		sf::Color lineColor = (i == 0) ? axisColor : gridColor;
		
		// Yatay çizgiler
		gridLines.append(sf::Vertex(sf::Vector2f(0.f, screenY), lineColor));
		gridLines.append(sf::Vertex(sf::Vector2f(width, screenY), lineColor));
		
		text.setString(std::to_string(i));
		text.setPosition({ origin.x + 2.f, screenY });
		window.draw(text);
	}

	window.draw(gridLines);
}

Plotter::Plotter()
{
	if (!m_font.openFromFile(".\\x64\\Debug\\FunnelSans-VariableFont.ttf")) {
		std::cerr << "Failed to load font" << std::endl;
	}
}

