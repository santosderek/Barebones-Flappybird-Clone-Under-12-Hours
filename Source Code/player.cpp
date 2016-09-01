#include "player.h"

Player::Player():
	shape()
{
	speed = 150.f;
	gravity = 2.f;

	velocity.x = 0.f;
	velocity.y = 0.f;

	moveup = false;
	movedown = false;
	moveleft = false;
	moveright = false;

	setShape();

}
void Player::setShape()
{
	shape.setFillColor(sf::Color(245, 147, 10));
	shape.setOutlineColor(sf::Color::Black);
	shape.setOutlineThickness(2.f);
	shape.setSize(sf::Vector2f(20, 20));
}

sf::RectangleShape& Player::shape_reference()
{
	return shape;
}

void Player::setposition(float x, float y)
{
	shape.setPosition(x, y);
}

void Player::move(sf::Time time, bool &pressReady)
{

	if (moveup && pressReady)
	{
		velocity.y -= speed;
		pressReady = false;
	}
	else if (!moveup && !pressReady)
	{
		pressReady = true;
	}

	velocity.y += gravity;

	if (velocity.y > speed)
	{
		velocity.y = speed;
	}

	shape.move(velocity * time.asSeconds());
}
