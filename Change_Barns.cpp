#include "Change_Barns.h"

void Change_Barns::Operate(Menu& menu){
    cout << "������� ����� �������� ������� �������. \n";
    cout << "����� ������� ������: ";
    int first = menu.GetNumber(0, 100);
    cout << "����� ������� ������: ";
    int second = menu.GetNumber(0, 100);
    menu.game.Change_Barns(first, second);
}

Change_Barns change_barns;