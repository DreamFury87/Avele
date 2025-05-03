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
    cout << "\n=================== Игровое меню ===================\n";
    cout << "1 - Выбрать лунку" << endl;
    cout << "2 - Новая игра" << endl;
    cout << "3 - Сохранить" << endl;
    cout << "4 - Загрузить сохранение" << endl;
    cout << "5 - Правила игры" << endl;
    cout << "6 - Выход" << endl;    

    game.Draw();
    cout << "====================================================" << endl;

    return GetNumber(1, 6);
}

// Функция для ввода целого числа с проверкой
int Menu::GetNumber(int min, int max) {
    int number = min - 1;
    while (true) {
        cin >> number;
        if ((number >= min) && (number <= max) && (cin.peek() == '\n')) {
            break;
        }
        else {
            cout << "Пожалуйста, введите число (в пределах от " << min << " до " << max << "): " << endl;
            cin.clear();
            while (cin.get() != '\n') {};
        }
    }
    return number;
}

// Функция для обработки выбора лунки
void Menu::Select_Hole() {
    int low; int high;
    if (game.Get_Current_Player() == FIRST) {
        low = 0; high = 5;
    }     
    else {
        low = 6; high = 11;
    }       

    cout << "Выберите лунку (" << low << " - " << high << "): ";
    int idx = GetNumber(low, high);
    cout << "Вы выбрали лунку " << idx << endl;

    game.Move(idx);   
}

// Функция для начала новой игры
void Menu::New_Game() {
    cout << "Начинаем новую игру..." << endl;
    game = Drawable();
    // Здесь можно добавить логику для инициализации новой игры
}

// Функция для вывода правил игры
void Menu::Game_Rules() {
    cout << "Выводим правила игры..." << endl;
}

// Функция для сохранения игры
void Menu::Save_Game() {
    cout << "Сохранение игры..." << endl;
    game.Save_Game();
    // Здесь можно добавить логику для сохранения состояния игры
}

//Загрузка сохранения
void Menu::Load_Game() {
    string path;
    cout << "Введите путь к файлу: " << endl;
    cin >> path;
    cout << "Загрузка сохранения..." << endl;
    game.Load_Game(path);
    // Здесь можно добавить логику для загрузки состояния игры
}

// возврат в функцию с основным меню
void Menu::ExitBack() {
    cout << "Нажмите Enter." << endl;
    cin.get(); cin.get();
}
