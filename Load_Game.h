#pragma once
#include "Action.h"
#include "Menu.h"
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

