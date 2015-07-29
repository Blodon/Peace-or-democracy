#include <iostream>

#pragma once
using namespace std;

class texture
{
public:
	texture(bool typep);
	texture(texture& neighbour);
	bool created;
	bool access;
	bool ground;
	float hight;
	short int typeg;

};

