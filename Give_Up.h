#pragma once
#include "Action.h"
#include "Menu.h"
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