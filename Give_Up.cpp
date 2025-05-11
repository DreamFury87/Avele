#include "Give_Up.h"

void Give_Up::Operate(Menu& menu) {
    cout << "Вы уверены, что хотите сдаться (да/нет)?\n";
    string answer = menu.Get_Answer();

    if (yes.find(answer) != yes.end()) {
        menu.game.Give_Up();
    }
    else {
        cout << "Партия будет доиграна!\n";
    }
}

Give_Up give_up;