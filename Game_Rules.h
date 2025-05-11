#pragma once
#include "Action.h"
#include "Menu.h"
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

