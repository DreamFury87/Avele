#include "Hole.h"
#include <iostream>
using namespace std;

//����������� �� ���������
Hole::Hole() {	
	pebbles = 4;	
}

//����������� � �������� ����������� ������
Hole::Hole(int value) {
	pebbles = value;
}

//����������
Hole::~Hole() {
	//cout << "Hole is deleted!" << endl;
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
