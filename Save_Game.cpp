#include "Save_Game.h"

void Save_Game::Operate(Menu& menu) {
	cout << "Сохранение игры..." << endl;
	menu.game.Save_Game();
}

Save_Game save_game;