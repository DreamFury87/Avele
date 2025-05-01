#include "Hole.h"
#include <iostream>
using namespace std;

//Конструктор по умолчанию
Hole::Hole() {	
	pebbles = 4;	
}

//Конструктор с заданным количеством камней
Hole::Hole(int value) {
	pebbles = value;
}

//Деструктор
Hole::~Hole() {
	//cout << "Hole is deleted!" << endl;
}

//Обновление количества камней в лунке
void Hole::Update(int value) {
	pebbles = value;
}

//Получение количества камней в лунке
int Hole::Get_Pebbles() {
	return pebbles;
}

Hole& Hole::operator ++(int){
	Hole old = *this;
	pebbles++;
	return old;
}

Hole& Hole::operator --(int){
	Hole old = *this;
	pebbles--;
	return old;
}
