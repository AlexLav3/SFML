#pragma once
#include <SFML\Graphics.hpp>
#include "animation.h"

class Player
{

public: 

	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float Speed);

	void Update(float deltaTime); 
	void Draw(sf::RenderWindow &window); 

	sf::Vector2f GetPosition() { return body.getPosition(); };

private: 

	sf::RectangleShape body; 
	Animation animation;
	unsigned int row;
	float Speed; 
	bool FaceRight; 

};

