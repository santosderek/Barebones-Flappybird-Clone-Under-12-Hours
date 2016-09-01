#include "bars.h"

Bars::Bars()
{
	barWidth = 50;
	speed.x = -100.f;
}

sf::RectangleShape& Bars::shape_one_reference()
{
	return barOne;
}

sf::RectangleShape& Bars::shape_two_reference()
{
	return barTwo;
}

void Bars::setposition(float x, float y)
{
	barOne.setPosition(x, y);
}

void Bars::move(sf::Time time)
{
	barOne.move(speed * time.asSeconds());
	barTwo.move(speed * time.asSeconds());
}

void Bars::setBar(float window_width, float window_height)
{
	barOne.setPosition(window_width, 0);
	barOne.setFillColor(sf::Color(31, 224, 66));
	barOne.setOutlineColor(sf::Color::Black);
	barOne.setOutlineThickness(2.f);
	barOne.setSize(sf::Vector2f(barWidth, window_height / 3));

	barTwo.setPosition(window_width, window_height / 2);
	barTwo.setFillColor(sf::Color(31, 224, 66));
	barTwo.setOutlineColor(sf::Color::Black);
	barTwo.setOutlineThickness(2.f);
	barTwo.setSize(sf::Vector2f(barWidth, window_height / 2));
}

bool Bars::isOffScreen()
{
	if (barOne.getPosition().x + barWidth < 0) {
		return true;
	}

	return false;
}

bool Bars::intersects(Player& player)
{

	if (barOne.getGlobalBounds().intersects(player.shape_reference().getGlobalBounds()))
	{
		return true;
	}

	if (barTwo.getGlobalBounds().intersects(player.shape_reference().getGlobalBounds()))
	{
		return true;
	}

	return false;
}
