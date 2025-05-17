#pragma once
#include "Hole.h"
#include <string>
#include <vector>

using namespace std;

enum STATE { FIRST, SECOND, DRAW, ACTIVE};

class Game
{
protected:	
	vector<Hole> holes; // Вектор лунок
	STATE current_player; // Текущий игрок (FIRST или SECOND)
	STATE game_active; //Состояние игры

	int first_barn; //Амбар первого игрока
	int second_barn; //Амбар второго игрока

	int Next_Hole(int); //Обход против часовой стрелки
	int Prev_Hole(int); //Обход по часовой стрелке

	void Append_to_Barn(int); // Сбор камней

public:
	Game();
	Game(vector<Hole> loaded_holes, int barn1, int barn2, STATE player, STATE active);

	~Game() {}
	
	void Move(int hole_number); //Логика хода
	
	void Save_Game(); //Сохранение
	void Load_Game(string path); //Загрузка

	void Give_Up(); //Сдаться
	void Offer_a_Draw(); //Предложить ничью
	void Print_Win();

	STATE Get_Current_Active() const { return game_active; } //Текущее состояние игры
	STATE Get_Current_Player() const { return current_player; } //Текущий игрок

	void Switch_Player(); //Переключение игроков
	
	STATE Check_Win_Condition(); //Проверка условия выигрыша
	bool Own_Holes(int); //Свои-чужие лунки	

	void Change_Holes(vector<int> cheat_holes);
	void Change_Barns(int, int);
};

