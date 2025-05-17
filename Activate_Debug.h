#pragma once
#include "Action.h"
#include "Menu.h"

class Activate_Debug :
    public Action
{
protected:
	std::string name;
public:
	Activate_Debug() : name("Активировать Debug mode") {}
	const std::string& Get_Name() const { return name; }
	void Operate(Menu&);
};

extern Activate_Debug activate_debug;

