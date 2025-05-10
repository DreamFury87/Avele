#include "Menu.h"
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");  
    system("chcp 1251");    
    system("color F2");

    Menu menu;

    while (true) {
        int choice = menu.Console_Menu();
        switch (choice) {
        case 1:
            menu.Select_Hole();
            break;
        case 2:
            menu.New_Game();
            break;
        case 3:
            menu.Save_Game();
            break;
        case 4:
            menu.Load_Game();
            break;
        case 5:
            menu.Game_Rules();
            break;
        case 6:
            menu.Offer_a_Draw();
            break;
        case 7:
            menu.Give_Up();
            break;
        case 8:
            cout << "Выход из игры." << endl;
            return 0;
        case 9:
            menu.Change_Holes();
            break;
        case 10:
            menu.Change_Barns();
            break;
        case 13:
            menu.Cheat_Mode();
            break;
        }
    }    
    return 0;
}