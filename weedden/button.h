#include <SFML/Graphics.hpp>
#pragma once
class button {
public:
	sf::Sprite sprite;
	button(sf::Texture t, float PosX, float PosY) {
		texture = t;
		status = 0;
		sizeX = 132;
		sizeY = 29;
		setSprite(PosX, PosY);
	}
	~button() {}
	void setStatus(int st)
	{
		status = st;
		sprite.setTextureRect(getIntRect());
	}
private:
	int sizeX, sizeY, tabulation, status;
	sf::Texture texture;
	sf::Texture getTexture() {
		return texture;
	}
	sf::IntRect getIntRect() {
		return sf::IntRect(sizeX*status, 0, sizeX, sizeY);
	}
	void setSprite(float PosX, float PosY)
	{
		sprite.setTexture(texture);
		sprite.setTextureRect(getIntRect());
		sprite.setPosition(PosX, PosY);
	}
};

