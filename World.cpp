#include "World.h"
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;


World::World(string name, int x , int y)
{
	sz=x;
	wy=y;
	unsigned short int szMapy;
	unsigned short int wyMapy;
	szMapy=x;
	wyMapy=y;

	mapName = name;
	mapName += ".txt";

    FILE *ms=fopen( mapName.c_str() , "wb");
	fwrite((char*)&szMapy,1,sizeof(int), ms);
	fwrite((char*)&wyMapy,1,sizeof(int), ms);

	for(int i=0; i<sz ; i++){
		for(int j=0; j<wy ; j++){
			
	fwrite((char*)&i,1,sizeof(int), ms);
	fwrite((char*)&j,1,sizeof(int), ms);

			for(int pSz=0; pSz<100 ; pSz++){
				for(int pWy=0; pWy<100 ; pWy++){
						texture generText(true);
						fwrite((char*)&pSz,1,sizeof(int), ms);
						fwrite((char*)&pWy,1,sizeof(int), ms);
						fwrite((char*)&generText.created,1,sizeof(bool), ms);
						fwrite((char*)&generText.access,1,sizeof(bool), ms);
						fwrite((char*)&generText.ground,1,sizeof(bool), ms);
						fwrite((char*)&generText.hight,1,sizeof(int), ms);
						fwrite((char*)&generText.typeg,1,sizeof(int), ms);
						generText.~texture();
				}
			}

		}
	}
	fclose(ms);

	cSz=0;
	cWy=0;
	setZeroPosition();
}



World::World(string name)
{

	mapName = name;
	mapName += ".txt";

	FILE *ms=fopen( mapName.c_str() , "rb");


		{
		char* temp = new char[sizeof(int)];
		fread((char*)temp, 1 , sizeof(int) , ms);
		int* number1 = (int*)(temp);
		sz=*number1;
		}
		{
		char* temp = new char[sizeof(int)];
		fread((char*)temp, 1 , sizeof(int) , ms);
		int* number1 = (int*)(temp);
		wy=*number1;
		}

		cout<<"szerokosc: "<<sz<<endl;
		cout<<"wysokosc: "<<wy<<endl;

		
		cSz=0;
		cWy=0;
		setZeroPosition();

}





char World::rysujMiejsce(int x, int y){
	if(place[0][0][x][y]->access==0){
		return '#';
	} else {
		if(place[0][0][x][y]->typeg==0) return ' ';
		if(place[0][0][x][y]->typeg==1) return '%';
		if(place[0][0][x][y]->typeg==2) return '*';
	}
}


void World::rysujMape(){

	for(int x=0 ; x<sz+1 ; x++){
		for(int y=0 ; y<wy+1 ; y++){
			cout<<rysujMiejsce(x,y);
		}
	cout<<endl;
	}
}

void World::render(int qual){

	for(int i=qual ; i<(sz+1-qual) ; i++){	
		for(int j=qual ; j<(wy+1-qual) ; j++){	

			int los;
			int w=0;
			int z=0;
			int l=0;
			int high=0;
			int mod=0;

			for(int wys=-qual ; wys<(qual+1) ; wys++){
				for(int szer=-qual ; szer < (qual+1) ; szer++){
					if(place[0][0][i+wys][j+szer]->created==0){
							if(place[0][0][i][j]->typeg==0) w++;
							if(place[0][0][i][j]->typeg==1) z++;
							if(place[0][0][i][j]->typeg==2) l++;
							//high+=place[0][0][i][j]->hight;
							mod++;
					}else{
					if(place[0][0][i+wys][j+szer]->typeg==0) w++;
					if(place[0][0][i+wys][j+szer]->typeg==1) z++;
					if(place[0][0][i+wys][j+szer]->typeg==2) l++;
					//high+=place[0][0][i+wys][j+szer]->hight;
					mod++;
					}
				}
			}

			los=rand()%mod;
			los++;

			if(los>0 && los<=w) place[0][0][i][j]->typeg=0;			
			if(los>w && los<=(w+z)) place[0][0][i][j]->typeg=1;
			if(los>(w+z) && los<=(w+z+l)) place[0][0][i][j]->typeg=2;
		//	place[0][0][i][j]->hight=(high/mod);
			
			//cout<<i<<"."<<j<<" "<<place[0][0][i][j]->hight<<"		";
		}
			//cout<<endl;
	}
}


void World::render(int qual , short int choose){

	for(int i=qual ; i<(sz+1-qual) ; i++){	
		for(int j=qual ; j<(wy+1-qual) ; j++){	
			if(place[0][0][i][j]->typeg==choose){
			int los;
			int w=0;
			int z=0;
			int l=0;
			int high=0;
			int mod=0;

			for(int wys=-qual ; wys<(qual+1) ; wys++){
				for(int szer=-qual ; szer < (qual+1) ; szer++){
					
					if(place[0][0][i+wys][j+szer]->created==0){
							if(place[0][0][i][j]->typeg==0) w++;
							if(place[0][0][i][j]->typeg==1) z++;
							if(place[0][0][i][j]->typeg==2) l++;
							//high+=place[0][0][i][j]->hight;
							mod++;
					}else{
					if(place[0][0][i+wys][j+szer]->typeg==0) w++;
					if(place[0][0][i+wys][j+szer]->typeg==1) z++;
					if(place[0][0][i+wys][j+szer]->typeg==2) l++;
					//high+=place[0][0][i+wys][j+szer]->hight;
					mod++;
					}
				}
			}

			los=rand()%mod;
			los++;

			if(los>0 && los<=w) place[0][0][i][j]->typeg=0;			
			if(los>w && los<=(w+z)) place[0][0][i][j]->typeg=1;
			if(los>(w+z) && los<=(w+z+l)) place[0][0][i][j]->typeg=2;
		//	place[0][0][i][j]->hight=(high/mod);
			
			
			}
		}
			//cout<<endl;
	}
}


void World::drukujMape(){

        unsigned short int bfType;  
        unsigned long int bfSize;   
        unsigned short int bfReserved1;  
        unsigned short int bfReserved2;   
        unsigned long int bfOffBits;
        unsigned long int biSize;
        unsigned long int biWidth;  
        unsigned long int biHeight; 
        unsigned short int biPlanes;    
        unsigned short int biBitCount;  
        unsigned long int biCompression; 
        unsigned long int biSizeImage;  
        unsigned long int biXPelsPerMeter; 
        unsigned long int biYPelsPerMeter;
        unsigned long int biClrUsed;
        unsigned long int biClrImportant;
		
		static unsigned char color[3];
        //cout<<sizeof(bfSize);

        unsigned char znak1= 'B';
        unsigned char znak2= 'M';

        FILE *fp=fopen("mapa.bmp", "wb");
        bfType= (znak1) | (znak2 << 8); //'BM'
        bfSize=54+(((sz*100)*(wy*100))*24);
        bfReserved1 = 0;
        bfReserved1 = 0;
        bfOffBits=54;//1078;
        biSize=40;
        biWidth=(sz*100);
        biHeight=(wy*100);
        biPlanes=1;
        biBitCount=24;
        biCompression = 0;
        biSizeImage = (800*800)*24;
        biXPelsPerMeter = 0;
        biYPelsPerMeter = 0;
        biClrUsed = 0;
        biClrImportant =0;

        fwrite((char*)&bfType,1,sizeof(bfType), fp);
        fwrite((char*)&bfSize,1,sizeof(bfSize), fp);
        fwrite((char*)&bfReserved1,1,sizeof(bfReserved1), fp);
        fwrite((char*)&bfReserved2,1,sizeof(bfReserved2), fp);
        fwrite((char*)&bfOffBits,1,sizeof(bfOffBits), fp);
        fwrite((char*)&biSize,1,sizeof(biSize), fp);
        fwrite((char*)&biWidth,1,sizeof(biWidth), fp);
        fwrite((char*)&biHeight,1,sizeof(biHeight), fp);
        fwrite((char*)&biPlanes,1,sizeof(biPlanes), fp);
        fwrite((char*)&biBitCount,1,sizeof(biBitCount), fp);
        fwrite((char*)&biCompression,1,sizeof(biCompression), fp);
        fwrite((char*)&biSizeImage,1,sizeof(biSizeImage), fp);
        fwrite((char*)&biXPelsPerMeter,1,sizeof(biXPelsPerMeter), fp);
        fwrite((char*)&biYPelsPerMeter,1,sizeof(biYPelsPerMeter), fp);
        fwrite((char*)&biClrUsed,1,sizeof(biClrUsed), fp);
        fwrite((char*)&biClrImportant,1,sizeof(biClrImportant), fp);

        unsigned long piksel = 0 * 256^2 + 0 * 256 + 0;
        //cout<<sizeof(piksel);

        for(int tx=0; tx<(sz+1); tx++, cSz++){
			for(int ty=0; ty<(wy+1);ty++, cWy++){ 
				
				loadArea();

				for(int i=0; i<100; i++){
					for(int j=0; j<100; j++){

								int type;
								type=getTextureType(i,j);
					
								if(type==0){					
									color[0]=255;
									color[1]=0;
									color[2]=0;

								}else if(type==0){
									color[0]=255;
									color[1]=0;
									color[2]=0;

								}else if(type==1){
									color[0]=0;
									color[1]=200;
									color[2]=15;

								}else if(type==2){
									color[0]=100;
									color[1]=200;
									color[2]=100;
								}
							fwrite((char*)color, 1, sizeof(color), fp);
					}
				}
			}
        }
        fclose(fp);

		cSz=0;
		cWy=0;
		loadArea();

}


int World::getTextureType(int x, int y){
		int type=0;

		type=place[0][0][x][y]->typeg;

		return type;
}

void World::pokazPlik(){


	   FILE *ms=fopen("mapaconf2.txt", "rb");

		int bufSize=5;

		int szMapy;
		int wyMapy;

		bool created;
		bool access;
		bool ground;
		int hight;
		int typeg;


		{
		char* temp = new char[sizeof(int)];
		fread((char*)temp, 1 , sizeof(int) , ms);
		int* number1 = (int*)(temp);
		szMapy=*number1;
		}
		{
		char* temp = new char[sizeof(int)];
		fread((char*)temp, 1 , sizeof(int) , ms);
		int* number1 = (int*)(temp);
		wyMapy=*number1;
		}

		cout<<szMapy<<endl;
		cout<<wyMapy<<endl;

	for(int i=0; i<sz ; i++){
		for(int j=0; j<wy ; j++){

			{
			char* temp = new char[sizeof(int)];
			fread((char*)temp, 1 , sizeof(int) , ms);
			int* number1 = (int*)(temp);
			cout<<*number1<<endl;
			}
			{
			char* temp = new char[sizeof(int)];
			fread((char*)temp, 1 , sizeof(int) , ms);
			int* number1 = (int*)(temp);
			cout<<" "<<*number1<<"	";
			}
			for(int pSz=0; pSz<100 ; pSz++){
				for(int pWy=0; pWy<100 ; pWy++){



						{
						char* temp = new char[sizeof(int)];
						fread((char*)temp, 1 , sizeof(int) , ms);
						int* number1 = (int*)(temp);
						cout<<*number1<<" ";
						}


						{
						char* temp = new char[sizeof(int)];
						fread((char*)temp, 1 , sizeof(int) , ms);
						int* number1 = (int*)(temp);
						cout<<*number1<<"	";
						}

						{
						char* temp = new char[sizeof(bool)];
						fread((char*)temp, 1 , sizeof(bool) , ms);
						bool* number2 = (bool*)(temp);
						created = *number2;
						}

						{
						char* temp = new char[sizeof(bool)];
						fread((char*)temp, 1 , sizeof(bool) , ms);
						bool* number2 = (bool*)(temp);
						access = *number2;
						}



						{
						char* temp = new char[sizeof(bool)];
						fread((char*)temp, 1 , sizeof(bool) , ms);
						bool* number2 = (bool*)(temp);
						ground = *number2;
						}



						{
						char* temp = new char[sizeof(int)];
						fread((char*)temp, 1 , sizeof(int) , ms);
						int* number1 = (int*)(temp);
						hight = *number1;
						}


						{
						char* temp = new char[sizeof(int)];
						fread((char*)temp, 1 , sizeof(int) , ms);
						int* number1 = (int*)(temp);
						typeg = *number1;
						}


						texture generText(created, access, ground, hight, typeg);
						generText.pokazParametry();
						generText.~texture();
				}
			}

		}
	}


		fclose(ms);


}


void World::catchTextures(){

	
	   FILE *ms=fopen("mapaconf2.txt", "rb");

		int szMapy;
		int wyMapy;

		bool created;
		bool access;
		bool ground;
		int hight;
		int typeg;


		{
		char* temp = new char[sizeof(int)];
		fread((char*)temp, 1 , sizeof(int) , ms);
		int* number1 = (int*)(temp);
		szMapy=*number1;
		}
		{
		char* temp = new char[sizeof(int)];
		fread((char*)temp, 1 , sizeof(int) , ms);
		int* number1 = (int*)(temp);
		wyMapy=*number1;
		}

	for(int i=0; i<sz ; i++){
		for(int j=0; j<wy ; j++){

			{
			char* temp = new char[sizeof(int)];
			fread((char*)temp, 1 , sizeof(int) , ms);
			int* number1 = (int*)(temp);
			//cout<<*number1<<endl;
			}
			{
			char* temp = new char[sizeof(int)];
			fread((char*)temp, 1 , sizeof(int) , ms);
			int* number1 = (int*)(temp);
			//cout<<" "<<*number1<<"	";
			}
			for(int pSz=0; pSz<100 ; pSz++){
				for(int pWy=0; pWy<100 ; pWy++){



						{
						char* temp = new char[sizeof(int)];
						fread((char*)temp, 1 , sizeof(int) , ms);
						int* number1 = (int*)(temp);
						//cout<<*number1<<" ";
						}


						{
						char* temp = new char[sizeof(int)];
						fread((char*)temp, 1 , sizeof(int) , ms);
						int* number1 = (int*)(temp);
						//cout<<*number1<<"	";
						}

						{
						char* temp = new char[sizeof(bool)];
						fread((char*)temp, 1 , sizeof(bool) , ms);
						bool* number2 = (bool*)(temp);
						created = *number2;
						}

						{
						char* temp = new char[sizeof(bool)];
						fread((char*)temp, 1 , sizeof(bool) , ms);
						bool* number2 = (bool*)(temp);
						access = *number2;
						}



						{
						char* temp = new char[sizeof(bool)];
						fread((char*)temp, 1 , sizeof(bool) , ms);
						bool* number2 = (bool*)(temp);
						ground = *number2;
						}



						{
						char* temp = new char[sizeof(int)];
						fread((char*)temp, 1 , sizeof(int) , ms);
						int* number1 = (int*)(temp);
						hight = *number1;
						}


						{
						char* temp = new char[sizeof(int)];
						fread((char*)temp, 1 , sizeof(int) , ms);
						int* number1 = (int*)(temp);
						typeg = *number1;
						}

						if(i==cSz && j==cWy){
							place[0][0][pSz][pWy] = new texture(created, access, ground, hight, typeg);
						}else{
						texture generText(created, access, ground, hight, typeg);
						generText.~texture();
						}

				}
			}

		}
	}
		fclose(ms);

}






void World::loadArea(){

	for(int i=0; i<100; i++){
		for(int j=0; j<100; j++){
			place[0][0][i][j]->~texture();
		}
	}

	catchTextures();

}


void World::setZeroPosition(){	
	catchTextures();
}