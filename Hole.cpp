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

//���������� ���������� ������ � �����
void Hole::Update(int value) {
	pebbles = value;
}

//��������� ���������� ������ � �����
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
