#include <SFML/Graphics.hpp>
#include <iostream>
#include "button.h"

void Init(sf::Texture t[],button *b[],int size);
int setButtonHover(button *b[], int hover, int size);
int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "Test");
	//--create variables--
	const int button_counts = 5;
	int button_hover = 0;
	sf::Texture textures[button_counts];
	button *buttons[button_counts];

	//--init variables--
	sf::Texture(*ptr_textures)[button_counts] = &textures;
	button *(*ptr_buttons)[button_counts] = &buttons;
	Init(*ptr_textures,*ptr_buttons,button_counts);
	setButtonHover(*ptr_buttons, button_hover, button_counts);

	//--window main loop--
	int tick_counter = 1000;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				window.close();
		tick_counter++;
		if (tick_counter>=500) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				tick_counter = 0;
				button_hover++;
				button_hover = setButtonHover(*ptr_buttons, button_hover, button_counts);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				tick_counter = 0;
				button_hover--;
				button_hover = setButtonHover(*ptr_buttons, button_hover, button_counts);
			}
		}
		window.clear();
		for (int i = 0; i < button_counts;i++)
			window.draw(buttons[i]->sprite);
		window.display();
	}
	return 0;
}
void Init(sf::Texture t[],button *b[],int size)
{
	t[0].loadFromFile("textures\\button_create.png");
	t[1].loadFromFile("textures\\button_connect.png");
	t[2].loadFromFile("textures\\button_options.png");
	t[3].loadFromFile("textures\\button_about.png");
	t[4].loadFromFile("textures\\button_exit.png");
	for (int i = 0; i < size; i++)
		b[i] = new button(t[i], 10, 10 + 39 * i);
}
int setButtonHover(button *b[], int hover, int size)
{
	for (int i = 0; i < size; i++)
		b[i]->setStatus(0);
	if (hover < 0)hover = size - 1;
	if (hover >= size)hover = 0;
	b[hover]->setStatus(1);
	return hover;
}