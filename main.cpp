#include "Menu.h"
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
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
            cout << "Выход из игры." << endl;
            return 0;
            
        }
    }    
    return 0;
}