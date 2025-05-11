#pragma once
#include "Action.h"
#include "Menu.h"
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

