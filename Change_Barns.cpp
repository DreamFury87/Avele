#include "Change_Barns.h"

void Change_Barns::Operate(Menu& menu){
    cout << "Введите новые значения амбаров игроков. \n";
    cout << "Амбар первого игрока: ";
    int first = menu.GetNumber(0, 100);
    cout << "Амбар второго игрока: ";
    int second = menu.GetNumber(0, 100);
    menu.game.Change_Barns(first, second);
}

Change_Barns change_barns;