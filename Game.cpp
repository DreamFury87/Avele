#include "Game.h"
#include <iostream>
using namespace std;

//Конструктор по умолчанию
Game::Game() {
    first_barn = 0; second_barn = 0;
    current_player = FIRST;
    game_active = true;

    for (int i = 0; i < 12; ++i) {
        holes.push_back(Hole());
    }
}

Game::~Game() {
}

//Простая "отрисовка" в консоли
void Game::Draw() {
    cout << endl;
    if (current_player == FIRST)
        cout << "Ход первого игрока: \n";
    else
        cout << "Ход второго игрока: \n";

    cout << "First Barn: " << first_barn << endl;
    cout << "Second Barn: " << second_barn << endl;
    for (int i = 0; i < 12; ++i) {
        cout << "[ " << i << " ]: " << holes[i].Get_Pebbles() << "   ";
        if (i == 5) cout << endl;
    }    
    cout << endl;
}

//Ход
void Game::Move(int hole_number) {
    if (holes[hole_number].Get_Pebbles() == 0) {
        cout << "Лунка Пуста!\n";
        return;
    }

    int idx = hole_number;
    while (holes[hole_number].Get_Pebbles()) {
        if (idx > 5 and idx < 11) {
            idx++;
        }
        else if (idx > 0) {
            idx--;
        }
        else if (idx == 11) {
            idx = 5;
        }
        else {
            idx = 6;
        }
        holes[idx]++;
        holes[hole_number]--;               
    }

    //holes[hole_number].Update(0);
    this->Switch_Player();
        
}

//Сохранение игры
void Game::Save_Game(){
}

STATE Game::Get_Current_Player() {
    return current_player;
}

//Загрузка сохранения
void Game::Load_Game(string path) {
}

//Получение массива лунок:
vector<Hole> Game::Get_Holes() {
    return holes;
}

//Переключение между игроками
void Game::Switch_Player() {
    if (current_player == FIRST)
        current_player = SECOND;
    else
        current_player = FIRST;
}

//Новая игра
void Game::New_Game() {
	*this = Game();
}

bool Game::Check_Win_Condition() {
    // Логика для проверки условий выигрыша
    return false; 
}