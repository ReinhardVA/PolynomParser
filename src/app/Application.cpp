#include "Application.h"
#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>
#include "imgui.h"

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
	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			ImGui::SFML::ProcessEvent(window, *event);
			if (event->is<sf::Event::Closed>())
				window.close();
		}
		ImGui::SFML::Update(window, deltaClock.restart());
		
		ImGui::ShowDemoWindow();
		
		// UI işlemleri
		ImGui::Begin("Hello, world!");
		if (ImGui::Button("Hesapla")) {
			// Plotter'ı çağır
		}
		ImGui::End();

		window.clear(sf::Color(0, 0, 0));
		// plotter.render(window);

		ImGui::SFML::Render(window);
		
		window.display();
	}
}
