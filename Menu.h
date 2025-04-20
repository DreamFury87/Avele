#pragma once
#include <SFML/Graphics.hpp>

enum MOVE{FIRST, SECOND};

class Menu
{
public:
	Menu();

	int GetNumber(int, int);
	//int Loop();

	void ExitBack();
	void Move(MOVE, int);
	void New_Game();

	~Menu();
};
//int Loop();