#include "menu.h"
menu::menu(float width, float hight)
{
	/*sf::Texture texture;
	if (!texture.loadFromFile("bitmap.pmp"));
	{

	}
	sf::Sprite sprite;
	sprite.setTexture(texture);*/
	if (!font.loadFromFile("arial.ttf"))

	{
	}



	mainmenu[0].setFont(font);
	mainmenu[0].setFillColor(sf::Color::Green);
	mainmenu[0].setString("play");
	mainmenu[0].setCharacterSize(72);
	mainmenu[0].setPosition(sf::Vector2f(500, 300));

	

	mainmenu[2].setFont(font);
	mainmenu[2].setFillColor(sf::Color::White);
	mainmenu[2].setString("Close");
	mainmenu[2].setCharacterSize(72);
	mainmenu[2].setPosition(sf::Vector2f(700, 500));
	mainmenuselected = 0;

}
menu::~menu()
{

}
void menu::draw(sf::RenderWindow& window)
{
	for (int m = 0; m < 3; m++)
	{
		window.draw(mainmenu[m]);
	}
}
void menu::moveUp()
{
	if (mainmenuselected - 1 >= -1)
	{
		mainmenu[mainmenuselected].setFillColor(sf::Color::White);
		mainmenuselected--;
		if (mainmenuselected == -1)
		{

			mainmenuselected = 2;
		}
		mainmenu[mainmenuselected].setFillColor(sf::Color::Green);
	}
}
void menu::moveDown()
{
	if (mainmenuselected + 1 <= MAX_MAIN_MENU)
	{
		mainmenu[mainmenuselected].setFillColor(sf::Color::White);
		mainmenuselected++;
		if (mainmenuselected == 3)
		{
			mainmenuselected = 0;
		}

		mainmenu[mainmenuselected].setFillColor(sf::Color::Green);

	}
}

