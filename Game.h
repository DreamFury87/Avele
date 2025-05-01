#pragma once
#include "Hole.h"
#include <string>
#include <vector>

using namespace std;

enum STATE { FIRST, SECOND };

class Game
{
protected:	
	vector<Hole> holes; // Вектор лунок
	STATE current_player; // Текущий игрок (FIRST или SECOND)
	bool game_active; //Состояние игры

	int first_barn; //Амбар первого игрока
	int second_barn; //Амбар второго игрока

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

	STATE Get_Current_Player();
};

