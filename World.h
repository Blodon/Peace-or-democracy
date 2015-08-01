#include "texture.h"
#include <iostream>
#include <string>

#pragma once
using namespace std;

class World
{
	private:
	texture* place[2][2][99][99];

	public:
	World(string name, int x , int y);
	World(string name);
	int sz, wy, cSz, cWy;
	string mapName;

	char rysujMiejsce(int x , int y);
	void rysujMape();
	void render(int qual);
	void render(int qual, short int choose);
	void drukujMape();
	int getTextureType(int x, int y);
	void pokazPlik();
	void setZeroPosition();
	void catchTextures();
	void loadArea();

};

