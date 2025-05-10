#pragma once
#include "Drawable.h"
#include <unordered_set>
#include <algorithm>

const unordered_set<string> valid_answers = { "да", "нет", "ДА", "НЕТ", "Да", "Нет",
	"дА", "неТ", "НеТ", "НЕт", "нЕт", "нЕТ" };

const unordered_set<string> yes = { "да", "ДА", "Да", "дА"};
const unordered_set<string> no = { "нет", "НЕТ", "Нет", "неТ", "НеТ", "НЕт", "нЕт", "нЕТ" };

class Menu{
private:
	Drawable game;
	bool debug_mode;

public:
	Menu();
	~Menu();

	int Console_Menu();
	int GetNumber(int, int);
	string Get_Answer();
		
	void ExitBack();

	void Select_Hole(); //Выбрать лунку
	void New_Game(); //Новая игра
	void Game_Rules(); //Правила игры
	void Save_Game(); //Сохранить игру

	void Give_Up(); //Сдаться
	void Offer_a_Draw(); //Предложить ничью

	void Load_Game(); //Загрузить сохранение

	void Cheat_Mode();
	void Change_Holes();
	void Change_Barns();
};
