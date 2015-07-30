#include <iostream>
#include <conio.h>
#include "World.h"
#include <time.h>

using namespace std;

int main(){



	//srand(time(NULL));
	int x,y,qual;

	cin>>x;
	cin>>y;

	cout<<"Nowy swiat"<<endl;
	World swiat(x,y);

	for(;;){

	//swiat.rysujMape();
	int rend;
	short int whatToRender;
	swiat.drukujMape();
	cout<<"Podaj co renderowac 0-woda 1-ziemia 2-las"<<endl;
	cin>>whatToRender;
	
	cout<<"Podaj jakosc renderowania"<<endl;
	cin>>qual;
	cout<<"Podaj ilosc renderowan"<<endl;
	cin>>rend;
	cout<<"Loading..."<<endl;
	for(int i=0 ; i<rend ; i++){
		if(whatToRender>=3){
			swiat.render(qual);
		}else swiat.render(qual,whatToRender);
	}
	swiat.drukujMape();
	cout<<"Ready!"<<endl;
	}


	return 0;
}