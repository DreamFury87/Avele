#pragma once
#include "Action.h"
#include "Menu.h"

//Активация Дебага
class Activate_Debug : 	public Action
{
protected:
	std::string name;
public:
	Activate_Debug() : name("Активировать Debug mode") {}
	const std::string& Get_Name() const { return name; }
	void Operate(Menu&);
};
extern Activate_Debug activate_debug;

//Изменение амбаров
class Change_Barns : public Action
{
protected:
	std::string name;
public:
	Change_Barns() : name("Изменить амбары игроков (cheat!)") {}
	const std::string& Get_Name() const { return name; }
	void Operate(Menu& menu);
};
extern Change_Barns change_barns;

//Изменение лунок
class Change_Holes : public Action
{
protected:
	std::string name;
public:
	Change_Holes() : name("Изменить количество камней в лунках (cheat!)") {}
	const std::string& Get_Name() const { return name; }
	void Operate(Menu&);
};
extern Change_Holes change_holes;

//Правила
class Game_Rules : public Action
{
protected:
	std::string name;
public:
	Game_Rules() : name("Правила игры") {}
	const std::string& Get_Name() const { return name; }
	void Operate(Menu&);
};
extern Game_Rules game_rules;

//Досрочное завершение партии
class Give_Up : public Action
{
protected:
	std::string name;
public:
	Give_Up() : name("Сдаться") {}
	const std::string& Get_Name() const { return name; }
	void Operate(Menu&);
};
extern Give_Up give_up;

//Загрузка сохранения
class Load_Game : public Action
{
protected:
	std::string name;
public:
	Load_Game() : name("Загрузить сохранение") {}
	const std::string& Get_Name() const { return name; }
	void Operate(Menu&);
};
extern Load_Game load_game;

//Новая игра
class New_Game : public Action
{
protected:
	std::string name;
public:
	New_Game() : name("Новая игра") {}
	const std::string& Get_Name() const { return name; }
	void Operate(Menu& menu);
};
extern New_Game new_game;

//Ничья
class Offer_A_Draw : public Action
{
protected:
	std::string name;
public:
	Offer_A_Draw() : name("Предложить ничью") {}
	const std::string& Get_Name() const { return name; }
	void Operate(Menu&);
};
extern Offer_A_Draw offer_a_draw;

//Сохранение
class Save_Game : public Action
{
protected:
	std::string name;
public:
	Save_Game() : name("Сохранить игру") {}
	const std::string& Get_Name() const { return name; }
	void Operate(Menu&);
};
extern Save_Game save_game;

//Выбрать лунку
class Select_Hole : public Action
{
protected:
	std::string name;
public:
	Select_Hole() : name("Выбрать лунку") {}
	const std::string& Get_Name() const { return name; }
	void Operate(Menu&);
};
extern Select_Hole select_hole;


