#include "Game.h"
#include <iostream>
#include <fstream>
using namespace std;

//Конструктор по умолчанию
Game::Game() {
    first_barn = 0; second_barn = 0;
    current_player = FIRST;
    game_active = ACTIVE;

    for (int i = 0; i < 12; ++i) {
        holes.push_back(Hole());
    }
}
//Конструктор
Game::Game(vector<Hole> loaded_holes, int barn1, int barn2, STATE player = FIRST, STATE active = ACTIVE) {
    holes = loaded_holes;
    first_barn = barn1; second_barn = barn2;
    current_player = player;
    game_active = active;
}

void Game::Change_Holes(vector<int> cheat_holes) {
    for (int i = 0; i < 12; ++i) holes[i].pebbles = cheat_holes[i];    
}

void Game::Change_Barns(int first, int second) {
    first_barn = first; second_barn = second;
}

void Game::Print_Win() {
    //STATE active = this->Check_Win_Condition();
    if (game_active == FIRST) {
        cout << "Игра окончена!\nПобедил первый игрок. \n";
        return;
    }
    else if (game_active == SECOND) {
        cout << "Игра окончена!\nПобедил второй игрок! \n";
        return;
    }
    else if (game_active == DRAW) {
        cout << "Игра окончена!\nБоевая ничья! \n";
        return;
    }
}

//Сдаться
void Game::Give_Up() {
    if (current_player == FIRST) game_active = SECOND;    
    else game_active = FIRST;    
    this->Print_Win();
} 

//Предложить ничью
void Game::Offer_a_Draw() {
    game_active = DRAW;
    this->Print_Win();
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
    if (hole > 6 and hole < 11) {
        hole--;
    }
    else if (hole == 5) {
        hole = 11;
    }
    else if (hole >= 0 and hole < 5) {
        hole++;
    }
    else if (hole == 6) {
        hole = 0;
    }
    return hole;
}

bool Game::Own_Holes(int hole){
    if (current_player == FIRST) return (hole >= 0 and hole < 6);    
    else return (hole >= 6 and hole < 12);    
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
        //Пропускаем начальную лунку
        if(next_hole == hole_number) next_hole = this->Next_Hole(next_hole);
        holes[hole_number]--;
        holes[next_hole]++;

        //Сбор по кругу
        if (not(Own_Holes(next_hole))) {
            if (pebble == 1 and (holes[next_hole].pebbles == 2 or holes[next_hole].pebbles == 3)) {
                prev_hole = next_hole;
                do {
                    this->Append_to_Barn(prev_hole);
                    prev_hole = this->Prev_Hole(prev_hole);

                } while ((holes[prev_hole].pebbles == 2 or holes[prev_hole].pebbles == 3) and not(Own_Holes(prev_hole)));               
            }
        }        
        pebble = holes[hole_number].pebbles;        
    }        
    this->Switch_Player();
    game_active = this->Check_Win_Condition();    
}

// Сбор камней в амбар
void Game::Append_to_Barn(int i) {
    if (current_player == FIRST) first_barn += holes[i].pebbles;
    else second_barn += holes[i].pebbles;
    holes[i].pebbles = 0;
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
        for (auto& hole : holes)  load.read((char*)&(hole), sizeof(Hole));          
    }
    else {
        cout << "Файл сохранения не найден." << endl;
    }
    load.close();
}

//Переключение между игроками
void Game::Switch_Player() {
    if (current_player == FIRST) current_player = SECOND;
    else current_player = FIRST;
}

// Логика для проверки условий выигрыша
STATE Game::Check_Win_Condition(){
    bool win_condition = true;
    for (int i = 0; i < 12; ++i)
        if (this->Own_Holes(i) and holes[i].pebbles) win_condition = false;
        
    if (win_condition) {
        if (first_barn > second_barn) {
            game_active = FIRST;
        }
        else if(first_barn == second_barn) {
            game_active = DRAW;
        }
        else {
            game_active = SECOND;
        }
    }
    else {
        game_active = ACTIVE;
    }
    this->Print_Win();
    return game_active;
}