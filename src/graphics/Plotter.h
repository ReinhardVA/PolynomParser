#pragma once
#include<vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

class Plotter
{
	// Pencereyi oluşturmaz, gelen pencere referansını kullanır, matematiksel verileri alır çizgiye dönüştürür, Gridleri, eksenleri çizer, çizgileri çizer, renkleri ve kalınlıkları ayarlar.
public:
	void setPoints(const std::vector<sf::Vector2f>& points, sf::RenderWindow& window);
};

