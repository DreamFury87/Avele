#include "Change_Holes.h"

void Change_Holes::Operate(Menu& menu) {
    cout << "Введите новые значения 12 лунок: \n";
    vector<int> holes(12);
    cout << "Лунки первого игрока:\n";
    for (int i = 0; i < 6; ++i) {
        cout << "[ " << i << " ]: ";
        holes[i] = menu.GetNumber(0, 100);
    }
    cout << "Лунки второго игрока:\n";
    for (int i = 6; i < 12; ++i) {
        cout << "[ " << i << " ]: ";
        holes[i] = menu.GetNumber(0, 100);
    }
    menu.game.Change_Holes(holes);
}

Change_Holes change_holes;