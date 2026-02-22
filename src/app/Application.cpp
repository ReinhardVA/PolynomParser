#include "Application.h"
#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>
#include "imgui.h"
#include "../core/lexer/Lexer.h"
#include <DS/LinkedList.h>
#include "../core/lexer/TokenType.h"
#include "../core/parser/ASTNode.h"
#include "../core/parser/Parser.h"
#include "../core/evaluator/Evaluator.h"
#include <string>
#include "../graphics/Plotter.h"
#include <vector>
#include <SFML/System/Vector2.hpp>

Application::Application() : window(sf::VideoMode({ 800, 600 }), "Math Plotter")
{
	window.setFramerateLimit(60);
	bool isSuccess = ImGui::SFML::Init(window);
	if (!isSuccess)
	{
		// log
	}
}

Application::~Application()
{
	ImGui::SFML::Shutdown();
}

void Application::run()
{
	char inputText[64] = "";
	std::string inputStr;
	std::vector<sf::Vector2f> points;
	Plotter plotter;
	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			ImGui::SFML::ProcessEvent(window, *event);
			if (event->is<sf::Event::Closed>())
				window.close();
		}
		ImGui::SFML::Update(window, deltaClock.restart());
				
		// UI işlemleri
		ImGui::Begin("Math Graph Drawer");
		plotter.drawGrid(window);
		ImGui::InputText("Denklemi giriniz", inputText, IM_ARRAYSIZE(inputText));
		if (ImGui::Button("Hesapla")) {
			// inputText'i lexer'a gönder, tokenları al, parser'a gönder, AST'yi al, evaluator'a gönder, x aralığını belirle, sonuçları plotter'a gönder.
			inputStr = inputText;
			points = calculateGraph(inputStr);
		}
		ImGui::End();

		window.clear(sf::Color(0, 0, 0));
		
		plotter.drawGrid(window);
		plotter.drawGraph(points, window);
		ImGui::SFML::Render(window);
		
		window.display();
	}
}


std::vector<sf::Vector2f> Application::calculateGraph(std::string& inputString)
{
	double maxX = 10.0f;
	double step = 0.1f;
	double minX = -10.0f;

	std::vector<sf::Vector2f> points;
	Lexer lexer(inputString);
	LinkedList<Token> tokens = lexer.tokenize();
	ASTNode* root = ParseToAST(tokens);
	Evaluator evaluator;
	for (double x = minX; x <= maxX; x += step) {
		double y = evaluator.EvaluateExpression(root, x);
		points.emplace_back(static_cast<float>(x), static_cast<float>(y));
	}
	return points;
}
