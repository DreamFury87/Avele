#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu(){
    debug_mode = false;
}

Menu::~Menu(){
    //cout << "Menu is destroyed\n";
}

int Menu::Console_Menu() {
    int min = 1; int max = 8;
    if (debug_mode) max = 10;

    cout << "\n=================== ������� ���� ===================\n";
    cout << "1 - ������� �����" << endl;
    cout << "2 - ����� ����" << endl;
    cout << "3 - ���������" << endl;
    cout << "4 - ��������� ����������" << endl;
    cout << "5 - ������� ����" << endl;
    cout << "6 - ���������� �����" << endl;
    cout << "7 - �������" << endl;
    cout << "8 - �����" << endl;

    if (debug_mode) {
        cout << "9 - �������� ���������� ������ � ������ (cheat!)" << endl;
        cout << "10 - �������� ������ ������� (cheat!)" << endl;
    }

    game.Draw();
    cout << "====================================================" << endl;
        
    return GetNumber(min, max);
}

void Menu::Cheat_Mode(){
    debug_mode = true;
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
void Menu::Change_Holes() {
    cout << "������� ����� �������� 12 �����: \n";
    vector<int> holes(12);
    cout << "����� ������� ������:\n";
    for (int i = 0; i < 6; ++i) {
        cout << "[ " << i << " ]: ";
        holes[i] = GetNumber(0, 100);
    }
    cout << "����� ������� ������:\n";
    for (int i = 6; i < 12; ++i) {
        cout << "[ " << i << " ]: ";
        holes[i] = GetNumber(0, 100);
    }
    game.Change_Holes(holes);
}

void Menu::Change_Barns() {
    cout << "������� ����� �������� ������� �������. \n";
    cout << "����� ������� ������: ";
    int first = GetNumber(0, 100);
    cout << "����� ������� ������: ";
    int second = GetNumber(0, 100);
    game.Change_Barns(first, second);
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
//�������
void Menu::Give_Up() {
    cout << "�� �������, ��� ������ ������� (��/���)?\n";
    string answer = this->Get_Answer();

    if (yes.find(answer) != yes.end()) {
        game.Give_Up();
    }
    else {
        cout << "������ ����� ��������!\n";
    }    
}

//���������� �����
void Menu::Offer_a_Draw() {
    if (game.Get_Current_Player() == FIRST) {
        cout << "������ ";
    }
    else {
        cout << "������ ";
    }
    cout << "����� ���������� �����.\n������� (��/���)?\n";
    string answer = this->Get_Answer();

    if (yes.find(answer) != yes.end()) {
        game.Offer_a_Draw();
    }
    else {
        cout << "������� �����!\n";
    }
} 

// ������� ��� ��������� ������ �����
void Menu::Select_Hole() {
    STATE active = game.Get_Current_Active();
    if (active != ACTIVE) {
        cout << "���� ���������!\n";
        return;
    }
        
    int low; int high;
    if (game.Get_Current_Player() == FIRST) {
        low = 0; high = 5;
    }     
    else {
        low = 6; high = 11;
    }     
    cout << "�������� ����� (" << low << " - " << high << "): ";
    int idx = GetNumber(low, high);
    cout << "�� ������� ����� " << idx << endl;

    game.Move(idx);   
}

// ������� ��� ������ ����� ����
void Menu::New_Game() {
    cout << "�������� ����� ����..." << endl;
    game = Drawable();    
}

// ������� ��� ������ ������ ����
void Menu::Game_Rules() {
    cout << "������� ������� ����..." << endl;
    cout << "������� ���� ������� �� ���� �����, �� 6 ����� � ������. ������ ����� \n";
    cout << "� ������ ���� �������� 4 �����. ������ ��� ����������� ������, ������� - \n";
    cout << "- ��� ����������. ������ ������ ���� �� �������. ��� ���� ����� ����� ����� \n";
    cout << "�� ����� �����* �������� �����, � ������������ �� �� ������ � ������ ��������� �����, \n";
    cout << "�������� ������ ������� �������. ��������� ����� ������ ������������.\n";
    cout << "���� ����� ������ ��������� ������ � ����� ���������� � ����� �������� 2 ��� 3 �����\n";
    cout << "(������� ������ ��� ����������) �� ����� �������� ����� �� �����, �������� �� �������\n";
    cout << "�������, �� ��� ���, ���� ��� ��������������� ������� �����������. \n";
    cout << "���� ����� �� ����� ������� ��������� ���, �� �������� ��� ���������� �����, \n";
    cout << "���� ������������� � ������������ ����������.\n"; 
    cout << "\nP.S. ����� ������� ������ � 0 �� 5, ����� ������� - � 6 �� 11\n";
}

// ������� ��� ���������� ����
void Menu::Save_Game() {
    cout << "���������� ����..." << endl;
    game.Save_Game();    
}

//�������� ����������
void Menu::Load_Game() {
    string path;
    cout << "������� ���� � �����: ";
    cin >> path;
    cout << "�������� ����������..." << endl;
    game.Load_Game(path);    
}

// ������� � ������� � �������� ����
void Menu::ExitBack() {
    cout << "������� Enter." << endl;
    cin.get(); cin.get();
}
