#include "mainwindow.h"

MainWindow::MainWindow() :
	window(sf::VideoMode((int) window_width, (int) window_height), "Solving Mathmatical Problems")
{
	float distance_between = window_width;

	for (Bars &item : bar)
	{
		item.setBar(distance_between, window_height);
		distance_between += 450.f;
	}

	player.setposition(window_width / 2.f, window_height / 2.f);

	pressReady = true;
	game_over = false;

	if (!font.loadFromFile("BERNHC.TTF"))
	{
		throw std::invalid_argument("Could not find font file: (BERNHC.TTF)");
	}

	gameOverText.setString("GAME OVER!  Press Esc to Quit.");
	gameOverText.setFillColor(sf::Color::Black);
	gameOverText.setCharacterSize(30);
	gameOverText.setFont(font);

	gameOverText.setOrigin(gameOverText.getGlobalBounds().width / 2.f,
					   gameOverText.getGlobalBounds().height / 2.f);

	gameOverText.setPosition(window_width / 2.f, window_height / 2.f);

}

void MainWindow::render()
{
	window.clear(sf::Color(69, 127, 186));

	if (!game_over)
	{
		for (Bars &item : bar)
		{
			window.draw(item.shape_one_reference());
			window.draw(item.shape_two_reference());
		}

		window.draw(player.shape_reference());

	}
	else
	{
		window.draw(gameOverText);
	}

	window.display();
}

void MainWindow::process_events()
{
	sf::Event event;
	while (window.pollEvent(event))
	{

		switch (event.type)
		{
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
			{
				window.close();
				break;
			}
			playerActions(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			playerActions(event.key.code, false);
			break;
		case sf::Event::Closed:
			window.close();
			break;
		}
	}
}

void MainWindow::playerActions(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W)
	{
		player.moveup = isPressed;
	}
}

void MainWindow::update(sf::Time time)
{
	if (!game_over)
	{
		player.move(time, pressReady);

		for (Bars &item : bar)
		{
			item.move(time);

			if (item.intersects(player))
			{
				game_over = true;
			}

		}

		if (player.shape_reference().getPosition().y + player.shape_reference().getGlobalBounds().height >= window_height)
		{
			player.setposition(player.shape_reference().getPosition().x, window_height - player.shape_reference().getGlobalBounds().height);
		}

		if (player.shape_reference().getPosition().y <= 0)
		{
			player.setposition(player.shape_reference().getPosition().x, 1.f);
		}

	}

}

void MainWindow::run()
{
	sf::Clock clock;
	sf::Time TimeExpected = sf::seconds(1.f / 60.f);
	sf::Time sinceLastUpdate = sf::Time::Zero;

	while (window.isOpen())
	{
		process_events();
		sinceLastUpdate += clock.restart();

		while (sinceLastUpdate > TimeExpected)
		{
			sinceLastUpdate -= TimeExpected;
			process_events();
			update(TimeExpected);
		}

		render();
	}
}
