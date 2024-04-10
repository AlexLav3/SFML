#include "animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount; 
	this->switchTime = switchTime; 
	totalTime = 0.0f; 
	currentImage.x = 0.0f; 

	uvRect.width = texture->getSize().x / float(imageCount.x); 
	uvRect.height = texture->getSize().y / float(imageCount.y);

}

void Animation::Update(int row, float deltaTIme, bool FaceRight)
{
	currentImage.y = row; 
	totalTime += deltaTIme; 

	if (totalTime >= switchTime) {

		totalTime -= switchTime; 
		currentImage.x++; 
		if (currentImage.x >= imageCount.x) {

			currentImage.x = 0; 

		}

	}
	
	uvRect.top = currentImage.y * uvRect.height; 

	if (FaceRight) {

      uvRect.left = currentImage.x * uvRect.width;
	  uvRect.width = abs(uvRect.width);

	}
	else
	{
		uvRect.left = (currentImage.x +1 )* abs(uvRect.width);
		uvRect.width = -abs(uvRect.width); 

	}
}
