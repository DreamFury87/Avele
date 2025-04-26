#include "Game.h"
#include <iostream>
using namespace std;

//����������� �� ���������
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

//������� "���������" � �������
void Game::Draw() {
    cout << endl;
    if (current_player == FIRST)
        cout << "��� ������� ������: \n";
    else
        cout << "��� ������� ������: \n";

    cout << "First Barn: " << first_barn << endl;
    cout << "Second Barn: " << second_barn << endl;
    for (int i = 0; i < 12; ++i) {
        cout << "[ " << i << " ]: " << holes[i].Get_Pebbles() << "   ";
        if (i == 5) cout << endl;
    }    
    cout << endl;
}

//���
void Game::Move(int hole_number) {
    if (holes[hole_number].Get_Pebbles() == 0) {
        cout << "����� �����!\n";
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

//���������� ����
void Game::Save_Game(){
}

STATE Game::Get_Current_Player() {
    return current_player;
}

//�������� ����������
void Game::Load_Game(string path) {
}

//��������� ������� �����:
vector<Hole> Game::Get_Holes() {
    return holes;
}

//������������ ����� ��������
void Game::Switch_Player() {
    if (current_player == FIRST)
        current_player = SECOND;
    else
        current_player = FIRST;
}

//����� ����
void Game::New_Game() {
	*this = Game();
}

bool Game::Check_Win_Condition() {
    // ������ ��� �������� ������� ��������
    return false; 
}