#pragma once
#include <string>

class Menu;

class Action
{
public:
	virtual ~Action() {}
	virtual const std::string& Get_Name() const = 0;
	virtual void Operate(Menu&) = 0;
};


