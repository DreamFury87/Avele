#include "Game.h"
#include <iostream>
#include <fstream>
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

//Конструктор
Game::Game(vector<Hole> loaded_holes, int barn1, int barn2, STATE player = FIRST, bool active = true) {
    holes = loaded_holes;
    first_barn = barn1; second_barn = barn2;
    current_player = player;
    game_active = active;
}

Game::~Game() {
}

//Простая "отрисовка" в консоли
void Game::Draw() {
    cout << endl;
    if (current_player == FIRST)
        cout << "Ход первого игрока \n";
    else
        cout << "Ход второго игрока \n";

    cout << "First Barn: " << first_barn << endl;
    cout << "Second Barn: " << second_barn << endl;
    for (int i = 0; i < 12; ++i) {
        cout << "[ " << i << " ]: " << holes[i].pebbles << "   ";
        if (i == 5) cout << endl;
    }    
    cout << endl;
}

//Обход лунок против часовой стрелки
int Game::Next_Hole(int hole){
    if (hole > 5 and hole < 11) {
        hole++;
    }
    else if (hole == 11) {
        hole = 5;
    }
    else if (hole > 0 and hole < 6) {
        hole--;
    }    
    else if(hole == 0){
        hole = 6;
    }
    return hole;
}

//Обход лунок по часовой стрелке
int Game::Prev_Hole(int hole) {
    if (hole > 5 and hole < 11) {
        hole--;
    }
    else if (hole == 5) {
        hole = 11;
    }
    else if (hole >= 0 and hole < 6) {
        hole++;
    }
    else if (hole == 6) {
        hole = 0;
    }
    return hole;
}

bool Game::Own_Holes(int hole){
    if (current_player == FIRST) {
        return (hole >= 0 and hole < 6);
    }
    else {
        return (hole >= 6 and hole < 12);
    }
}

//Ход
void Game::Move(int hole_number) {
    if (holes[hole_number].pebbles == 0) {
        cout << "Лунка Пуста!\n";
        return;
    }

    int next_hole = hole_number; int prev_hole = hole_number;
    int pebble = holes[hole_number].pebbles;

    while (pebble > 0) {
        //Посев в следующую лунку
        next_hole = this->Next_Hole(next_hole);
        holes[hole_number]--;
        holes[next_hole]++;

        //Сбор по кругу
        if (not(Own_Holes(next_hole))) {
            if (pebble == 1 and (holes[next_hole].pebbles == 2 or holes[next_hole].pebbles == 3)) {
                prev_hole = next_hole;
                do {
                    if (current_player == FIRST)
                        first_barn += holes[prev_hole].pebbles;
                    else
                        second_barn += holes[prev_hole].pebbles;

                    holes[prev_hole].pebbles = 0;
                    prev_hole = this->Prev_Hole(prev_hole);

                } while (holes[prev_hole].pebbles == 2 or holes[prev_hole].pebbles == 3);
                break;
            }
        }        
        pebble = holes[hole_number].pebbles;        
    }        
    this->Switch_Player();        
}

//Сохранение игры
void Game::Save_Game(){
    ofstream save("save.bin", ios::binary | ios::out);
    if (save.is_open()) {
        // Сохраняем текущего игрока
        save.write((char*)&current_player, sizeof(current_player)); 

        //game_active
        save.write((char*)&game_active, sizeof(game_active));

        // Сохраняем амбары
        save.write((char*)&first_barn, sizeof(int));
        save.write((char*)&second_barn, sizeof(int));

        // Сохраняем каждую лунку
        for (auto& hole : holes) {            
            save.write((char*)&(hole), sizeof(Hole));
        }       
    }
    else {
        cout << "Не удалось открыть файл для сохранения." << endl;
    }
    
    save.close();
}

STATE Game::Get_Current_Player() {
    return current_player;
}

//Загрузка сохранения
void Game::Load_Game(string path) {
    ifstream load(path, ios::binary | ios::in);
    
    if (load.is_open()) {
        // Загружаем текущего игрока
        load.read((char*)&current_player, sizeof(current_player)); 

        //game_active
        load.read((char*)&game_active, sizeof(game_active));

        // Загружаем амбары
        load.read((char*)&first_barn, sizeof(int));
        load.read((char*)&second_barn, sizeof(int));
                
        // Загружаем каждую лунку
        for (auto& hole : holes) {            
            load.read((char*)&(hole), sizeof(Hole));
        }
    }
    else {
        cout << "Файл сохранения не найден." << endl;
    }
    load.close();
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
    if (first_barn == 24 or second_barn == 24) {
        return true;
    }
    else {
        return false;
    }   
}