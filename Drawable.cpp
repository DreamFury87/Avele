#include "Drawable.h"

//Улучшенный вывод в консоль
void Drawable::Draw() {	 
    cout << endl;
    if (current_player == FIRST)
        cout << "\t\tХод первого игрока \n\n";
    else
        cout << "\t\tХод второго игрока \n\n";

    cout << "Амбар первого игрока: " << first_barn << endl;
    cout << endl;
    cout << "  0  \t  1  \t  2  \t  3  \t  4  \t  5  " << endl;
    cout << ".----. \t.----. \t.----. \t.----. \t.----. \t.----." << endl;    
    for (int i = 0; i < 12; ++i) {        
        this->Draw_Pebbles(i);
        if (i == 5) {
            cout << "\n*----* \t*----* \t*----* \t*----* \t*----* \t*----* " << endl;
            cout << ".----. \t.----. \t.----. \t.----. \t.----. \t.----. " << endl;
        }
    }    
    cout << "\n*----* \t*----* \t*----* \t*----* \t*----* \t*----*" << endl;
    cout << "  6  \t  7  \t  8  \t  9  \t  10  \t  11  " << endl;
    cout << "\nАмбар второго игрока: " << second_barn << endl;    
}

//Вывод камней в лунках
void Drawable::Draw_Pebbles(int i) {
    if (holes[i].pebbles < 10) {
        cout << "| " << holes[i].pebbles << "  |  ";
    }
    else {
        cout << "| " << holes[i].pebbles << " |  ";
    }    
}