#include "Select_Hole.h"

void Select_Hole::Operate(Menu& menu) {
    STATE active = menu.game.Get_Current_Active();
    if (active != ACTIVE) {
        cout << "���� ���������!\n";
        return;
    }

    int low; int high;
    if (menu.game.Get_Current_Player() == FIRST) {
        low = 0; high = 5;
    }
    else {
        low = 6; high = 11;
    }
    cout << "�������� ����� (" << low << " - " << high << "): ";
    int idx = menu.GetNumber(low, high);
    cout << "�� ������� ����� " << idx << endl;

    menu.game.Move(idx);
}

Select_Hole select_hole;