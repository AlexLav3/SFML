#include "player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float Speed) :
animation(texture,imageCount,switchTime)
{
	this->Speed = Speed; 
	row = 0; 
	FaceRight = true; 

	body.setSize(sf::Vector2f(60.f, 80.0f));
	body.setPosition(206.0f, 206.0f); 
	body.setTexture(texture);

	body.setOrigin(body.getSize()/2.0f); 

}

void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f,0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

		movement.x -= Speed* deltaTime; 
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		movement.x += Speed * deltaTime;
	}

	if(movement.x==0.0f) {
		row = 0; 
     }
	else {
		row = 1;
		if (movement.x > 0.0f) {
			FaceRight = true;
		}
		else {
			FaceRight = false;
		}
	}
		animation.Update(row, deltaTime, FaceRight);
		body.setTextureRect(animation.uvRect);
		body.move(movement);
}


void Player::Draw(sf::RenderWindow &window)
{
	window.draw(body); 
}
