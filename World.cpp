#include "World.h"
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

World::World(int x , int y)
{
	sz=x;
	wy=y;

	for(int i=0 ; i<wy+1 ; i++){
		place[0][i] = new texture(false);
		place[sz][i] = new texture(false);
	}


	for(int i=1 ; i<sz ; i++){	
		place[i][0] = new texture(false);
		place[i][wy] = new texture(false);
	}

	for(int i=1 ; i<sz ; i++){	
		for(int j=1 ; j<wy ; j++){	
			place[i][j] = new texture(true);
		}
	}


}

char World::rysujMiejsce(int x, int y){
	if(place[x][y]->access==0){
		return '#';
	} else {
		if(place[x][y]->typeg==0) return ' ';
		if(place[x][y]->typeg==1) return '%';
		if(place[x][y]->typeg==2) return '*';
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
					if(place[i+wys][j+szer]->created==0){
							if(place[i][j]->typeg==0) w++;
							if(place[i][j]->typeg==1) z++;
							if(place[i][j]->typeg==2) l++;
							high+=place[i][j]->hight;
							mod++;
					}else{
					if(place[i+wys][j+szer]->typeg==0) w++;
					if(place[i+wys][j+szer]->typeg==1) z++;
					if(place[i+wys][j+szer]->typeg==2) l++;
					high+=place[i+wys][j+szer]->hight;
					mod++;
					}
				}
			}

			los=rand()%mod;
			los++;

			if(los>0 && los<=w) place[i][j]->typeg=0;			
			if(los>w && los<=(w+z)) place[i][j]->typeg=1;
			if(los>(w+z) && los<=(w+z+l)) place[i][j]->typeg=2;
			place[i][j]->hight=(high/mod);
			
			//cout<<i<<"."<<j<<" "<<place[i][j]->hight<<"		";
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

        std::cout<<sizeof(bfSize);

        unsigned char znak1= 'B';
        unsigned char znak2= 'M';

        FILE *fp=fopen("mapa.bmp", "wb");
        bfType= (znak1) | (znak2 << 8); //'BM'
        bfSize=54+((sz*wy)*24);
        bfReserved1 = 0;
        bfReserved1 = 0;
        bfOffBits=54;//1078;
        biSize=40;
        biWidth=sz;
        biHeight=wy;
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

        for(int tx=0; tx<sz;tx++)
        {
                for(int ty=0; ty<wy;ty++)
                { 

					
					if(place[tx][ty]->access==0){
						
						color[0]=0;
                        color[1]=0;
                        color[2]=0;

					}else if(place[tx][ty]->typeg==0){
						color[0]=255;
                        color[1]=0;
                        color[2]=0;

					}else if(place[tx][ty]->typeg==1){
						color[0]=0;
                        color[1]=200;
                        color[2]=15;

					}else if(place[tx][ty]->typeg==2){
						color[0]=100;
                        color[1]=200;
                        color[2]=100;
					}
			
                        fwrite((char*)color, 1, sizeof(color), fp);
                }
        }
        fclose(fp);




}