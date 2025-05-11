#pragma once
#include "Action.h"
#include "Menu.h"
class Change_Barns : public Action
{
protected:
	std::string name;
public:
	Change_Barns() : name("Изменить амбары игроков (cheat!)") {}
	const std::string& Get_Name() const  { return name; }
	void Operate(Menu& menu);
};

extern Change_Barns change_barns;

