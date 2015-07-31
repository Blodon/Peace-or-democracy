#include <iostream>

#pragma once
using namespace std;

class texture
{
public:
	texture(bool typep);
	texture(bool typep, short int prefer);
	texture(bool createdT, bool accessT, bool groundT, int hightT, int typegT);
	~texture();

	bool created;
	bool access;
	bool ground;
	int hight;
	short int typeg;

	void pokazParametry();
};

