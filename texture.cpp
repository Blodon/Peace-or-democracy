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


texture::texture(bool typep, short int prefer)
{
	/** Preferences chance to generate:
	1- more water ( 80% 10% 10% )
	2- more ground ( 10% 70% 20% )
	3- more forests ( 10% 30% 60% )
	**/

	int rnd;
	rnd=(rand()%10)+1;
	int w,z,f;

	if(prefer==1){
		w=8;
		z=1;
		f=1;
	}
	if(prefer==2){
		w=1;
		z=7;
		f=2;
	}
	if(prefer==3){
		w=1;
		z=3;
		f=6;
	}

	if(rnd>0 && rnd<=w) typeg=0;			
	if(rnd>w && rnd<=(w+z)) typeg=1;
	if(rnd>(w+z) && rnd<=(w+z+f)) typeg=2;


	created=1;

	if(typeg!=0)hight=rand()%100;
	if(typeg==0)hight=0;

}


