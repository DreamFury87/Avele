#include "Load_Game.h"

void Load_Game::Operate(Menu& menu) {
    string path;
    cout << "������� ���� � �����: ";
    cin >> path;
    cout << "�������� ����������..." << endl;
    menu.game.Load_Game(path);
}

Load_Game load_game;