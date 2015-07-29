#include "texture.h"
#include <iostream>
#include <time.h>

using namespace std;

texture::texture(bool typep)
{
	if(typep==0){
	created=0;
	access=0;
	}
	else{
	created=1;
	ground=rand()%2;
	if(ground==1){
		hight=rand()%100;
		typeg=rand()%3;
	}else{
		hight=0;
		typeg=0;
	}

	}

}

texture::texture(texture& neighbour)
{

}
