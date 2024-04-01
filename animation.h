#pragma once

#include <SFML\Graphics.hpp>

class animation
{

public: 

	animation(sf::Texture*texture, sf::Vector2u imageCount, float switchTime);
	
	sf::IntRect uvRect; 

	void Update(int row, float deltaTIme); 

private: 

	sf::Vector2u imageCount; 
	sf::Vector2u currentImage; 

	float totalTime; 
	float switchTime; 


};

