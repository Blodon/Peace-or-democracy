#include "texture.h"
#include <iostream>

#pragma once
using namespace std;

class World
{
	private:
	texture* place11[500][500];
	texture* place12[500][500];
	texture* place21[500][500];
	texture* place22[500][500];
	

public:
	World(int x , int y);
	int sz,wy;

	char rysujMiejsce(int x , int y);
	void rysujMape();
	void render(int qual);
	void render(int qual, short int choose);
	void drukujMape();
	int getTextureType(int x, int y);

};

