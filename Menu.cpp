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

    cout << "\n=================== Игровое меню ===================\n";
    cout << "1 - Выбрать лунку" << endl;
    cout << "2 - Новая игра" << endl;
    cout << "3 - Сохранить" << endl;
    cout << "4 - Загрузить сохранение" << endl;
    cout << "5 - Правила игры" << endl;
    cout << "6 - Предложить ничью" << endl;
    cout << "7 - Сдаться" << endl;
    cout << "8 - Выход" << endl;

    if (debug_mode) {
        cout << "9 - Изменить количество камней в лунках (cheat!)" << endl;
        cout << "10 - Изменить амбары игроков (cheat!)" << endl;
    }

    game.Draw();
    cout << "====================================================" << endl;
        
    return GetNumber(min, max);
}

void Menu::Cheat_Mode(){
    debug_mode = true;
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
void Menu::Change_Holes() {
    cout << "Введите новые значения 12 лунок: \n";
    vector<int> holes(12);
    cout << "Лунки первого игрока:\n";
    for (int i = 0; i < 6; ++i) {
        cout << "[ " << i << " ]: ";
        holes[i] = GetNumber(0, 100);
    }
    cout << "Лунки второго игрока:\n";
    for (int i = 6; i < 12; ++i) {
        cout << "[ " << i << " ]: ";
        holes[i] = GetNumber(0, 100);
    }
    game.Change_Holes(holes);
}

void Menu::Change_Barns() {
    cout << "Введите новые значения амбаров игроков. \n";
    cout << "Амбар первого игрока: ";
    int first = GetNumber(0, 100);
    cout << "Амбар второго игрока: ";
    int second = GetNumber(0, 100);
    game.Change_Barns(first, second);
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
//Сдаться
void Menu::Give_Up() {
    cout << "Вы уверены, что хотите сдаться (да/нет)?\n";
    string answer = this->Get_Answer();

    if (yes.find(answer) != yes.end()) {
        game.Give_Up();
    }
    else {
        cout << "Партия будет доиграна!\n";
    }    
}

//Предложить ничью
void Menu::Offer_a_Draw() {
    if (game.Get_Current_Player() == FIRST) {
        cout << "Первый ";
    }
    else {
        cout << "Второй ";
    }
    cout << "игрок предлагает ничью.\nПринять (да/нет)?\n";
    string answer = this->Get_Answer();

    if (yes.find(answer) != yes.end()) {
        game.Offer_a_Draw();
    }
    else {
        cout << "Никакой ничьи!\n";
    }
} 

// Функция для обработки выбора лунки
void Menu::Select_Hole() {
    STATE active = game.Get_Current_Active();
    if (active != ACTIVE) {
        cout << "Игра завершена!\n";
        return;
    }
        
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
}

// Функция для вывода правил игры
void Menu::Game_Rules() {
    cout << "Выводим правила игры..." << endl;
    cout << "Игровое поле состоит из двух рядов, по 6 лунок в каждом. Каждая лунка \n";
    cout << "в начале игры содержит 4 камня. Нижний ряд принадлежит игроку, верхний - \n";
    cout << "- его противнику. Игроки делают ходы по очереди. Для хода игрок берет камни \n";
    cout << "из любой своей* непустой лунки, и раскладывает их по одному в каждую следующую лунку, \n";
    cout << "двигаясь против часовой стрелки. Начальная лунка всегда пропускается.\n";
    cout << "Если игрок кладет последний камень в лунку противника и лунка содержит 2 или 3 камня\n";
    cout << "(включая только что положенный) то игрок собирает камни из лунок, двигаясь по часовой\n";
    cout << "стрелке, до тех пор, пока два вышеприведенных условия соблюдаются. \n";
    cout << "Если игрок не может сделать очередной ход, он собирает все оставшиеся камни, \n";
    cout << "игра заканчивается и определяется победитель.\n"; 
    cout << "\nP.S. Лунки первого игрока с 0 до 5, лунки второго - с 6 по 11\n";
}

// Функция для сохранения игры
void Menu::Save_Game() {
    cout << "Сохранение игры..." << endl;
    game.Save_Game();    
}

//Загрузка сохранения
void Menu::Load_Game() {
    string path;
    cout << "Введите путь к файлу: ";
    cin >> path;
    cout << "Загрузка сохранения..." << endl;
    game.Load_Game(path);    
}

// возврат в функцию с основным меню
void Menu::ExitBack() {
    cout << "Нажмите Enter." << endl;
    cin.get(); cin.get();
}
