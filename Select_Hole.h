#pragma once
#include "Action.h"
#include "Menu.h"
class Select_Hole : public Action
{
protected:
	std::string name;
public:
	Select_Hole() : name("������� �����") {}
	const std::string& Get_Name() const { return name; }
	void Operate(Menu& );
};

extern Select_Hole select_hole;
