#include "New_Game.h"

void New_Game::Operate(Menu& menu) {
	cout << "Начинаем новую игру..." << endl;
	menu.game = Drawable();
}

New_Game new_game;