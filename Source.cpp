#include <iostream>
#include <conio.h>
#include "World.h"
#include <time.h>
#include <string>

using namespace std;

int main(){

	srand(time(NULL));
	int x,y,qual;
	string mapn;
	int wyb;

	cout<<"1-Stworz nowy swiat\n2-Wczytaj swiat"<<endl;
	cin>>wyb;

		if(wyb==1){
			cin>>x;
			cin>>y;
			cout<<"Nowy swiat"<<endl;
		}
		if(wyb==1 || wyb==2){
			cout<<"Podaj nazwe swiata"<<endl;
			cin>> mapn;
		}

		//World swiat(mapn, x,y);
		World swiat(mapn);
		
	

	for(;;){
	
	int rend;
	short int whatToRender;

		cout<<"Drukowac?"<<endl;
		getch();
	//	swiat.pokazPlik();


		swiat.drukujMape();

		/**
	cout<<"Podaj co renderowac 0-woda 1-ziemia 2-las"<<endl;
	cin>>whatToRender;
	
	cout<<"Podaj jakosc renderowania"<<endl;
	cin>>qual;
	cout<<"Podaj ilosc renderowan"<<endl;
	cin>>rend;
	cout<<"Loading..."<<endl;
	for(int i=0 ; i<rend ; i++){
		if(whatToRender>=3){
			//swiat.render(qual);
		}else swiat.render(qual,whatToRender);
	}
	//swiat.drukujMape();

	**/

	cout<<"Ready!"<<endl;
	}


	return 0;
}