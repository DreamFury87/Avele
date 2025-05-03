#pragma once
#include "Game.h"
#include "Drawable.h"

class Menu{
private:
	Drawable game;

public:
	Menu();
	~Menu();

	int Console_Menu();
	int GetNumber(int, int);
		
	void ExitBack();

	void Select_Hole();
	void New_Game();
	void Game_Rules();
	void Save_Game();

	void Load_Game();

	void Print_Win();
};
