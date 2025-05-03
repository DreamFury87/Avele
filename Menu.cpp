#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu(){
    //cout << "Menu is created\n";
}

Menu::~Menu(){
    //cout << "Menu is destroyed\n";
}

int Menu::Console_Menu() {
    cout << "\n=================== ������� ���� ===================\n";
    cout << "1 - ������� �����" << endl;
    cout << "2 - ����� ����" << endl;
    cout << "3 - ���������" << endl;
    cout << "4 - ��������� ����������" << endl;
    cout << "5 - ������� ����" << endl;
    cout << "6 - �����" << endl;    

    game.Draw();
    cout << "====================================================" << endl;

    return GetNumber(1, 6);
}

// ������� ��� ����� ������ ����� � ���������
int Menu::GetNumber(int min, int max) {
    int number = min - 1;
    while (true) {
        cin >> number;
        if ((number >= min) && (number <= max) && (cin.peek() == '\n')) {
            break;
        }
        else {
            cout << "����������, ������� ����� (� �������� �� " << min << " �� " << max << "): " << endl;
            cin.clear();
            while (cin.get() != '\n') {};
        }
    }
    return number;
}

// ������� ��� ��������� ������ �����
void Menu::Select_Hole() {
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
    // ����� ����� �������� ������ ��� ������������� ����� ����
}

// ������� ��� ������ ������ ����
void Menu::Game_Rules() {
    cout << "������� ������� ����..." << endl;
}

// ������� ��� ���������� ����
void Menu::Save_Game() {
    cout << "���������� ����..." << endl;
    game.Save_Game();
    // ����� ����� �������� ������ ��� ���������� ��������� ����
}

//�������� ����������
void Menu::Load_Game() {
    string path;
    cout << "������� ���� � �����: " << endl;
    cin >> path;
    cout << "�������� ����������..." << endl;
    game.Load_Game(path);
    // ����� ����� �������� ������ ��� �������� ��������� ����
}

// ������� � ������� � �������� ����
void Menu::ExitBack() {
    cout << "������� Enter." << endl;
    cin.get(); cin.get();
}
