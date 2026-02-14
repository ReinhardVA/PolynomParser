#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <SFML/System/Vector2.hpp>

class Application
{
	// Pencereyi oluşturur, çizim yapacak elemanları çağırır sonucu ekrana basar.
	sf::RenderWindow window;
	sf::Clock deltaClock;

public:
	Application();
	~Application();
	void run();
	std::vector<sf::Vector2f> calculateGraph(std::string& inputString);
};

// Text box oluştur, denklemi al, denklemi lexer'a gönder, tokenları al, parser'a gönder, AST'yi al, evaluator'a gönder, x aralığını belirle, sonuçları plotter'a gönder.