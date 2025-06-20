#include "Actions.h"

//Активация дебага
void Activate_Debug::Operate(Menu& menu) {
	menu.Set_Debug_State(ENABLED);
}
Activate_Debug activate_debug;

//Изменение амбаров
void Change_Barns::Operate(Menu& menu) {
    cout << "Введите новые значения амбаров игроков. \n";
    cout << "Амбар первого игрока: ";
    int first = menu.GetNumber(0, 100);
    cout << "Амбар второго игрока: ";
    int second = menu.GetNumber(0, 100);
    menu.game.Change_Barns(first, second);
}
Change_Barns change_barns;

//Изменение лунок
void Change_Holes::Operate(Menu& menu) {
    cout << "Введите новые значения 12 лунок: \n";
    vector<int> holes(12);
    cout << "Лунки первого игрока:\n";
    for (int i = 0; i < 6; ++i) {
        cout << "[ " << i << " ]: ";
        holes[i] = menu.GetNumber(0, 100);
    }
    cout << "Лунки второго игрока:\n";
    for (int i = 6; i < 12; ++i) {
        cout << "[ " << i << " ]: ";
        holes[i] = menu.GetNumber(0, 100);
    }
    menu.game.Change_Holes(holes);
}
Change_Holes change_holes;

//Правила игры
void Game_Rules::Operate(Menu& menu) {
    cout << "Выводим правила игры..." << endl;
    cout << "Игровое поле состоит из двух рядов, по 6 лунок в каждом. Каждая лунка \n";
    cout << "в начале игры содержит 4 камня. Нижний ряд принадлежит игроку, верхний - \n";
    cout << "- его противнику. Игроки делают ходы по очереди. Для хода игрок берет камни \n";
    cout << "из любой своей* непустой лунки, и раскладывает их по одному в каждую следующую лунку, \n";
    cout << "двигаясь против часовой стрелки. Начальная лунка всегда пропускается.\n";
    cout << "Если игрок кладет последний камень в лунку противника и лунка содержит 2 или 3 камня\n";
    cout << "(включая только что положенный) то игрок собирает камни из лунок, двигаясь по часовой\n";
    cout << "стрелке, до тех пор, пока два вышеприведенных условия соблюдаются. \n";
    cout << "Если игрок не может сделать очередной ход, он собирает все оставшиеся камни, \n";
    cout << "игра заканчивается и определяется победитель.\n";
    cout << "\nP.S. Лунки первого игрока с 0 до 5, лунки второго - с 6 по 11\n";
}
Game_Rules game_rules;

//Сдаться
void Give_Up::Operate(Menu& menu) {
    cout << "Вы уверены, что хотите сдаться (да/нет)?\n";
    string answer = menu.Get_Answer();

    if (yes.find(answer) != yes.end()) {
        menu.game.Give_Up();
    }
    else {
        cout << "Партия будет доиграна!\n";
    }
}
Give_Up give_up;

//Загрузка из файла
void Load_Game::Operate(Menu& menu) {
    string path;
    cout << "Введите путь к файлу: ";
    cin >> path;
    cout << "Загрузка сохранения..." << endl;
    menu.game.Load_Game(path);
}
Load_Game load_game;

//Новая игра
void New_Game::Operate(Menu& menu) {
    cout << "Начинаем новую игру..." << endl;
    menu.game = Drawable();
}
New_Game new_game;

//Сохранение
void Save_Game::Operate(Menu& menu) {
    cout << "Сохранение игры..." << endl;
    menu.game.Save_Game();
}
Save_Game save_game;

//Предложение ничьи
void Offer_A_Draw::Operate(Menu& menu) {
    if (menu.game.Get_Current_Player() == FIRST) {
        cout << "Первый ";
    }
    else {
        cout << "Второй ";
    }
    cout << "игрок предлагает ничью.\nПринять (да/нет)?\n";
    string answer = menu.Get_Answer();

    if (yes.find(answer) != yes.end()) {
        menu.game.Offer_a_Draw();
    }
    else {
        cout << "Никакой ничьи!\n";
    }
}
Offer_A_Draw offer_a_draw;

//Выбрать лунку
void Select_Hole::Operate(Menu& menu) {
    STATE active = menu.game.Get_Current_Active();
    if (active != ACTIVE) {
        cout << "Игра завершена!\n";
        return;
    }

    int low; int high;
    if (menu.game.Get_Current_Player() == FIRST) {
        low = 0; high = 5;
    }
    else {
        low = 6; high = 11;
    }
    cout << "Выберите лунку (" << low << " - " << high << "): ";
    int idx = menu.GetNumber(low, high);
    cout << "Вы выбрали лунку " << idx << endl;

    menu.game.Move(idx);
}
Select_Hole select_hole;