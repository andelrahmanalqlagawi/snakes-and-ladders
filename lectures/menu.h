#pragma once
#include<SFML\Graphics.hpp>
#define MAX_MAIN_MENU 3
class menu
{
public:
	menu(float width, float hight);
	void draw(sf::RenderWindow& window);
	void moveUp();
	void moveDown();
	int mainmenupressed()
	{
		return mainmenuselected;
	}
	~menu();
private:
	int mainmenuselected;
	sf::Font font;
	sf::Text mainmenu[MAX_MAIN_MENU];
};
