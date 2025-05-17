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
#include "Activate_Debug.h"

using namespace std;

vector<Action*> base_action_list = { &select_hole, &game_rules,
&new_game, &load_game, &save_game, &offer_a_draw, &give_up, 0, &activate_debug};

vector<Action*> extended_action_list = { &select_hole, &game_rules,
&new_game, &load_game, &save_game, &offer_a_draw, &give_up, &change_barns, &change_holes, 0};

int main()
{
    setlocale(LC_ALL, "Russian");  
    system("chcp 1251");    
    system("color F0");

    Menu menu(base_action_list);
    
    while (Action* action = menu.Select_Action()) {
        action->Operate(menu);
        if (menu.Get_Debug_State() == ENABLED) {
            Drawable _game = menu.game;
            menu = Menu(extended_action_list, _game);            
        }
    }    
    return 0;
}