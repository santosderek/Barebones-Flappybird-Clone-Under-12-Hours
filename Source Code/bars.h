#pragma once
#include <SFML/Graphics.hpp>
#include "player.h"

class Bars
{
private: 
	sf::RectangleShape barOne;
	sf::RectangleShape barTwo;
	sf::Vector2f speed; 
	float barLength; 
	float barWidth; 
	
public: 
	Bars();
	sf::RectangleShape& shape_one_reference();
	sf::RectangleShape& shape_two_reference();
	
	void setposition(float, float);
	void move(sf::Time); 
	void setBar(float window_width, float window_height); 

	bool isOffScreen(); 
	bool intersects(Player&); 
	
};