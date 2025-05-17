#include "Activate_Debug.h"

void Activate_Debug::Operate(Menu& menu) {	
	menu.Set_Debug_State(ENABLED);
}

Activate_Debug activate_debug;