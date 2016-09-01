#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
	sf::RectangleShape shape; 
	sf::Vector2f velocity; 
	float gravity;
	float speed;
	
	void setShape(); 

public: 
	Player();
	
	sf::RectangleShape& shape_reference(); 
	
	void setposition(float, float);
	void move(sf::Time, bool&);
	
	bool moveup; 
	bool movedown; 
	bool moveleft; 
	bool moveright;

};