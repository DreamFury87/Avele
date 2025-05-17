#pragma once
#include "Hole.h"
#include <string>
#include <vector>

using namespace std;

enum STATE { FIRST, SECOND, DRAW, ACTIVE};

class Game
{
protected:	
	vector<Hole> holes; // ������ �����
	STATE current_player; // ������� ����� (FIRST ��� SECOND)
	STATE game_active; //��������� ����

	int first_barn; //����� ������� ������
	int second_barn; //����� ������� ������

	int Next_Hole(int); //����� ������ ������� �������
	int Prev_Hole(int); //����� �� ������� �������

	void Append_to_Barn(int); // ���� ������

public:
	Game();
	Game(vector<Hole> loaded_holes, int barn1, int barn2, STATE player, STATE active);

	~Game() {}
	
	void Move(int hole_number); //������ ����
	
	void Save_Game(); //����������
	void Load_Game(string path); //��������

	void Give_Up(); //�������
	void Offer_a_Draw(); //���������� �����
	void Print_Win();

	STATE Get_Current_Active() const { return game_active; } //������� ��������� ����
	STATE Get_Current_Player() const { return current_player; } //������� �����

	void Switch_Player(); //������������ �������
	
	STATE Check_Win_Condition(); //�������� ������� ��������
	bool Own_Holes(int); //����-����� �����	

	void Change_Holes(vector<int> cheat_holes);
	void Change_Barns(int, int);
};

