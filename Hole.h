#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Hole{
private:
	int pebbles;

public:	
	//int pebbles;

	Hole();
	Hole(int);
	~Hole();

	void Update(int);
	int Get_Pebbles();
	
	Hole& operator ++(int);
	Hole& operator --(int);
};

