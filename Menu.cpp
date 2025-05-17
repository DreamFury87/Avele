#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu(std::vector<Action*> _action_list) : action_list(_action_list) { 
    //debug_mode = DISABLED;    
}

Menu::Menu(std::vector<Action*> _action_list, Drawable game_) {  
    //cout << "created\n";
    debug_mode = ACTIVATED;
    action_list = _action_list;
    game = game_;     
}

Action* Menu::Select_Action() {
    int n_item = action_list.size();
    if (debug_mode == DISABLED) n_item--;
    cout << "\n=================== Игровое меню ===================\n";

    for (int i = 0; i < n_item; ++i) {
        cout << i + 1 << " - ";       

        if (action_list[i])
            cout << action_list[i]->Get_Name() << endl;
        else
            cout << "Выход" << endl;
    }
    game.Draw();
    cout << "=============================================\n";

    int item = GetNumber(1, n_item);
    if (item == 13) {      
        return action_list[8];
    }
    return action_list[item - 1];
}

//Ввод ответа с проверкой
string Menu::Get_Answer(){    
    string answer;
    while (true) {
        cin >> answer;        
        if ((valid_answers.find(answer) != valid_answers.end()) && (cin.peek() == '\n')) {
            break;
        }
        else {
            cout << "Пожалуйста, повторите ввод (да/нет): ";
            cin.clear();
            while (cin.get() != '\n') {};
        }
    }
    return answer;
}

// Функция для ввода целого числа с проверкой
int Menu::GetNumber(int min, int max) {
    int number = min - 1;
    while (true) {
        cin >> number;
        if ((number >= min) && (number <= max) && (cin.peek() == '\n')) {
            break;
        }
        //Вход в Cheat Mode
        else if (min == 1 and max == 8 and number == 13) {            
            break;
        }
        else {
            cout << "Пожалуйста, введите число (в пределах от " << min << " до " << max << "): ";
            cin.clear();
            while (cin.get() != '\n') {};
        }
    }
    return number;
}

