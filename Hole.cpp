#include "Hole.h"
#include <iostream>
using namespace std;

//����������� �� ���������
Hole::Hole() {
	//cout << "Hole's constructor is working" << endl;
	pebbles = 4;
	//cout << "Hole is created!" << endl;
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
