#include <iostream>

#pragma once
using namespace std;

class texture
{
public:
	texture(bool typep);
	texture(bool typep, short int prefer);
	bool created;
	bool access;
	bool ground;
	float hight;
	int typeg;

};

