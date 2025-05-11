#include "Load_Game.h"

void Load_Game::Operate(Menu& menu) {
    string path;
    cout << "Введите путь к файлу: ";
    cin >> path;
    cout << "Загрузка сохранения..." << endl;
    menu.game.Load_Game(path);
}

Load_Game load_game;