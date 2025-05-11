#pragma once
#include "Action.h"
#include "Menu.h"
class Offer_A_Draw : public Action
{
protected:
	std::string name;
public:
	Offer_A_Draw() : name("Предложить ничью") {}
	const std::string& Get_Name() const { return name; }
	void Operate(Menu&);
};

extern Offer_A_Draw offer_a_draw;

