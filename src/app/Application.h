#pragma once
#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>

class Application
{
	// Pencereyi oluşturur, çizim yapacak elemanları çağırır sonucu ekrana basar.
	sf::RenderWindow window;
	sf::Clock deltaClock;

public:
	Application();
	~Application();
	void run();
};

