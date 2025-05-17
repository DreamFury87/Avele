#pragma once
#include <vector>
#include "Drawable.h"
#include "Action.h"
#include <unordered_set>
#include <algorithm>

enum CHEAT { ENABLED, DISABLED, ACTIVATED };

const std::unordered_set<std::string> valid_answers = { "äà", "íåò", "ÄÀ", "ÍÅÒ", "Äà", "Íåò",
	"äÀ", "íåÒ", "ÍåÒ", "ÍÅò", "íÅò", "íÅÒ" };
const std::unordered_set<std::string> yes = { "äà", "ÄÀ", "Äà", "äÀ"};

class Menu{	
private:	
	std::vector<Action*> action_list;
	static inline CHEAT debug_mode{ DISABLED };

public:		
	Drawable game;	
	Menu(std::vector<Action*> _action_list);	
	Menu(std::vector<Action*> _action_list, Drawable game_);
	~Menu() {}
	
	Action* Select_Action();
	int GetNumber(int, int);

	bool Get_Debug_State() const { return debug_mode; }
	void Set_Debug_State(CHEAT debug_) { debug_mode = debug_; }

	std::string Get_Answer();		
};
