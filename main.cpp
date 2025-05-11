#include <iostream>
#include "Drawable.h"
#include "Menu.h"
#include "Action.h"
#include "Select_Hole.h"
#include "Game_Rules.h"
#include "Change_Holes.h"
#include "Change_Barns.h"
#include "New_Game.h"
#include "Load_Game.h"
#include "Save_Game.h"
#include "Offer_A_Draw.h"
#include "Give_Up.h"

using namespace std;

vector<Action*> action_list = { &select_hole, &game_rules,
&new_game, &load_game, &save_game, &offer_a_draw, &give_up, &change_barns, &change_holes};

int main()
{
    setlocale(LC_ALL, "Russian");  
    system("chcp 1251");    
    system("color F2");

    Menu menu(action_list);
    
    while (Action* action = menu.Select_Action()) {
        action->Operate(menu);
    }    
    return 0;
}