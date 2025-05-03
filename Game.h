#pragma once
#include "Hole.h"
#include <string>
#include <vector>

using namespace std;

enum STATE { FIRST, SECOND };

class Game
{
protected:	
	vector<Hole> holes; // ������ �����
	STATE current_player; // ������� ����� (FIRST ��� SECOND)
	bool game_active; //��������� ����

	int first_barn; //����� ������� ������
	int second_barn; //����� ������� ������

	int Next_Hole(int);
	int Prev_Hole(int);

public:
	Game();
	Game(vector<Hole> loaded_holes, int barn1, int barn2, STATE player, bool active);

	~Game();	
	
	void Move(int hole_number);
	void Draw();

	void New_Game();

	void Save_Game();
	void Load_Game(string path);

	void Switch_Player();
	vector<Hole> Get_Holes();

	bool Check_Win_Condition();
	bool Own_Holes(int);

	STATE Get_Current_Player();
};

