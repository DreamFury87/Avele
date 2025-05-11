#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu(std::vector<Action*> _action_list) : action_list(_action_list) { 
    debug_mode = false;
    action_list.push_back(0); 
}

Action* Menu::Select_Action() {
    int n_item = action_list.size();    
    cout << "\n=================== ������� ���� ===================\n";

    for (int i = 0; i < n_item; ++i) {
        cout << i + 1 << " - ";       

        if (action_list[i])
            cout << action_list[i]->Get_Name() << endl;
        else
            cout << "�����" << endl;
    }
    game.Draw();
    cout << "=============================================\n";

    int item = GetNumber(1, n_item);
    return action_list[item - 1];
}

//���� ������ � ���������
string Menu::Get_Answer(){    
    string answer;
    while (true) {
        cin >> answer;        
        if ((valid_answers.find(answer) != valid_answers.end()) && (cin.peek() == '\n')) {
            break;
        }
        else {
            cout << "����������, ��������� ���� (��/���): ";
            cin.clear();
            while (cin.get() != '\n') {};
        }
    }
    return answer;
}

// ������� ��� ����� ������ ����� � ���������
int Menu::GetNumber(int min, int max) {
    int number = min - 1;
    while (true) {
        cin >> number;
        if ((number >= min) && (number <= max) && (cin.peek() == '\n')) {
            break;
        }
        //���� � Cheat Mode
        else if (min == 1 and max == 8 and number == 13) {            
            break;
        }
        else {
            cout << "����������, ������� ����� (� �������� �� " << min << " �� " << max << "): ";
            cin.clear();
            while (cin.get() != '\n') {};
        }
    }
    return number;
}

