#pragma once
#include <SFML/Graphics.hpp>
#include "player.h"
#include "bars.h"

class MainWindow
{

private:
	float window_width = 800.f;
	float window_height = 600.f;

	bool pressReady;
	bool game_over;

	sf::RenderWindow window;
	sf::Text gameOverText;
	sf::Font font;

	void render();
	void process_events();
	void update(sf::Time);
	void playerActions(sf::Keyboard::Key, bool);

private:
	Player player;
	Bars bar[10];


public:
	MainWindow();
	void run(); 
};
