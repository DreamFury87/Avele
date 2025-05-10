#pragma once
#include "Drawable.h"
#include <unordered_set>
#include <algorithm>

const unordered_set<string> valid_answers = { "��", "���", "��", "���", "��", "���",
	"��", "���", "���", "���", "���", "���" };

const unordered_set<string> yes = { "��", "��", "��", "��"};
const unordered_set<string> no = { "���", "���", "���", "���", "���", "���", "���", "���" };

class Menu{
private:
	Drawable game;
	bool debug_mode;

public:
	Menu();
	~Menu();

	int Console_Menu();
	int GetNumber(int, int);
	string Get_Answer();
		
	void ExitBack();

	void Select_Hole(); //������� �����
	void New_Game(); //����� ����
	void Game_Rules(); //������� ����
	void Save_Game(); //��������� ����

	void Give_Up(); //�������
	void Offer_a_Draw(); //���������� �����

	void Load_Game(); //��������� ����������

	void Cheat_Mode();
	void Change_Holes();
	void Change_Barns();
};
