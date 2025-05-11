#pragma once
#include "Action.h"
#include "Menu.h"
class Change_Holes: public Action
{
protected:
	std::string name;
public:
	Change_Holes() : name("Изменить количество камней в лунках (cheat!)") {}
	const std::string& Get_Name() const{ return name; }
	void Operate(Menu&);
};

extern Change_Holes change_holes;

