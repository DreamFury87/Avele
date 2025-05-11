#pragma once
#include <vector>
#include "Drawable.h"
#include "Action.h"
#include <unordered_set>
#include <algorithm>

const std::unordered_set<std::string> valid_answers = { "��", "���", "��", "���", "��", "���",
	"��", "���", "���", "���", "���", "���" };
const std::unordered_set<std::string> yes = { "��", "��", "��", "��"};

class Menu{	
private:	
	bool debug_mode;
	std::vector<Action*> action_list;

public:	
	Drawable game;	
	Menu(std::vector<Action*> _action_list);	
	~Menu() {}
	
	Action* Select_Action();
	int GetNumber(int, int);
	std::string Get_Answer();		
};
