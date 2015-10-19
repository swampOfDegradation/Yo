#include <SFML/Graphics.hpp>
#include <iostream>
#include "button.h"

const int size = 5;
struct MainMenuButtons {
	sf::Texture texture[size];
	button *button[size];
};

void Init(struct MainMenuButtons *gv);
int setButtonHover(struct MainMenuButtons *gv, int hover);
int changeButtonHover(int *counter);
int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 300), "Test");
	struct MainMenuButtons variables;
	int hover = 0;
	Init(&variables);
	setButtonHover(&variables, hover);

	//--window main loop--
	int tick_counter = 8;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				window.close();
		switch (changeButtonHover(&tick_counter))
		{
		case 1: hover++; break;
		case 2: hover--; break;
		}
		hover = setButtonHover(&variables, hover);
		window.clear();
		for (int i = 0; i < size; i++)
		{
			window.draw(variables.button[i]->sprite);
		}
		window.display();
	}
	return 0;
}
int setButtonHover(struct MainMenuButtons *gv, int hover)
{
	for (int i = 0; i < size; i++)
		gv->button[i]->setStatus(0);
	if (hover < 0)hover = size - 1;
	if (hover >= size)hover = 0;
	gv->button[hover]->setStatus(1);
	return hover;
}
void Init(struct MainMenuButtons *gv) {
	gv->texture[0].loadFromFile("textures\\button_create.png");
	gv->texture[1].loadFromFile("textures\\button_connect.png");
	gv->texture[2].loadFromFile("textures\\button_options.png");
	gv->texture[3].loadFromFile("textures\\button_about.png");
	gv->texture[4].loadFromFile("textures\\button_exit.png");
	for (int i = 0; i < size; i++)
		gv->button[i] = new button(gv->texture[i], 10, 10 + 39 * i);
}
int changeButtonHover(int *counter)
{
	++*counter;
	if (*counter >= 750)
	{
		if (*counter >= 1000)*counter = 750;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			*counter=0;
			return 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			*counter = 0;
			return 2;
		}
	}
	return 0;
}