#include "Give_Up.h"

void Give_Up::Operate(Menu& menu) {
    cout << "�� �������, ��� ������ ������� (��/���)?\n";
    string answer = menu.Get_Answer();

    if (yes.find(answer) != yes.end()) {
        menu.game.Give_Up();
    }
    else {
        cout << "������ ����� ��������!\n";
    }
}

Give_Up give_up;