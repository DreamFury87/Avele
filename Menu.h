#pragma once
#include "Game.h"

class Menu{
private:
	Game game;

public:
	Menu();
	~Menu();

	int Console_Menu();
	int GetNumber(int, int);
		
	void ExitBack();

	void Select_Hole();
	void New_Game();
	void Save_Game();

	void Load_Game();
};
