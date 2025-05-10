#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Hole{
private:
	
public:	
	int pebbles;

	Hole();
	Hole(int);
	~Hole();
		
	Hole& operator ++(int);
	Hole& operator --(int);
};

