#include "Offer_A_Draw.h"

void Offer_A_Draw::Operate(Menu& menu) {
    if (menu.game.Get_Current_Player() == FIRST) {
        cout << "������ ";
    }
    else {
        cout << "������ ";
    }
    cout << "����� ���������� �����.\n������� (��/���)?\n";
    string answer = menu.Get_Answer();

    if (yes.find(answer) != yes.end()) {
        menu.game.Offer_a_Draw();        
    }
    else {
        cout << "������� �����!\n";
    }
}

Offer_A_Draw offer_a_draw;