#pragma once
#include "texture.h"
#include <iostream>

using namespace std;

class World
{
public:
	World(int x , int y);
	int sz,wy;
	texture* place[500][500];
	
	char rysujMiejsce(int x , int y);
	void rysujMape();
	void render(int qual);
	void drukujMape();

};

