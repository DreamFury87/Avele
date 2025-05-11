#pragma once
#include "Action.h"
#include "Menu.h"
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

