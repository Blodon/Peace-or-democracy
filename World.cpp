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
		
		if(sz<=500){
			if(wy<=500){
				place11[0][i] = new texture(false);
				place11[sz][i] = new texture(false);
			}

			if(wy>500){
				if(i<=500){
				place11[0][i] = new texture(false);
				place11[sz][i] = new texture(false);
				}else{
				place21[0][i-500] = new texture(false);
				place21[sz][i-500] = new texture(false);
				}
			}
		}

		if(sz>500){		
			if(wy<=500){
				place11[0][i] = new texture(false);
				place12[sz-500][i] = new texture(false);

			}

			if(wy>500){
				if(i<=500){
				place11[0][i] = new texture(false);
				place12[sz-500][i] = new texture(false);
				}else{
				place21[0][i-500] = new texture(false);
				place22[sz-500][i-500] = new texture(false);
				}
			}
		}



	}


	for(int j=1 ; j<sz ; j++){
	
		if(sz<=500){
			if(wy<=500){
				place11[j][0] = new texture(false);
				place11[j][wy] = new texture(false);
			}

			if(wy>500){
				if(j<=500){
				place11[j][0] = new texture(false);
				place21[j][wy-500] = new texture(false);
				}
			}
		}

		if(sz>500){		
			if(wy<=500){
				
				if(j<=500){
				place11[j][0] = new texture(false);
				place11[j][wy] = new texture(false);
				}else{
				place12[j-500][0] = new texture(false);
				place12[j-500][wy] = new texture(false);
				}
			}
			if(wy>500){
				if(j<=500){
				place11[j][0] = new texture(false);
				place21[j][wy-500] = new texture(false);
				}else{
				place12[j-500][0] = new texture(false);
				place22[j-500][wy-500] = new texture(false);
				}
			}
		}
	}

	//int pref;
/**
	for(int i=1 ; i<sz ; i++){
		//if(i<(sz/3)) pref=1;
		//if(i>=(sz/3) && i<(sz/2)) pref=2;
		//if(i>=(sz/2)) pref=3;
		for(int j=1 ; j<wy ; j++){	
			//place11[i][j] = new texture(true, pref);
			place11[i][j] = new texture(true);
			**/
	for(int i=1 ; i<wy ; i++){
		for(int j=1 ; j<sz ; j++){	

			if(sz<=500){
				if(wy<=500){
					place11[i][j] = new texture(true);
				}
				if(wy>500){
					if(i<=500)place11[i][j] = new texture(true);
					if(i>500)place21[i-500][j] = new texture(true);
				}
			}

			if(sz>500){
				if(wy<=500){
					if(j<=500)place11[i][j] = new texture(true);
					if(j>500)place12[i][j-500] = new texture(true);
				}
				if(wy>500){
					if(i<=500){
					if(j<=500)place11[i][j] = new texture(true);
					if(j>500)place12[i][j-500] = new texture(true);
					}else{
					if(j<=500)place21[i-500][j] = new texture(true);
					if(j>500)place22[i-500][j-500] = new texture(true);
					}
				}
			}

		}
	}


}

char World::rysujMiejsce(int x, int y){
	if(place11[x][y]->access==0){
		return '#';
	} else {
		if(place11[x][y]->typeg==0) return ' ';
		if(place11[x][y]->typeg==1) return '%';
		if(place11[x][y]->typeg==2) return '*';
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
					if(place11[i+wys][j+szer]->created==0){
							if(place11[i][j]->typeg==0) w++;
							if(place11[i][j]->typeg==1) z++;
							if(place11[i][j]->typeg==2) l++;
							high+=place11[i][j]->hight;
							mod++;
					}else{
					if(place11[i+wys][j+szer]->typeg==0) w++;
					if(place11[i+wys][j+szer]->typeg==1) z++;
					if(place11[i+wys][j+szer]->typeg==2) l++;
					high+=place11[i+wys][j+szer]->hight;
					mod++;
					}
				}
			}

			los=rand()%mod;
			los++;

			if(los>0 && los<=w) place11[i][j]->typeg=0;			
			if(los>w && los<=(w+z)) place11[i][j]->typeg=1;
			if(los>(w+z) && los<=(w+z+l)) place11[i][j]->typeg=2;
			place11[i][j]->hight=(high/mod);
			
			//cout<<i<<"."<<j<<" "<<place11[i][j]->hight<<"		";
		}
			//cout<<endl;
	}
}


void World::render(int qual , short int choose){

	for(int i=qual ; i<(sz+1-qual) ; i++){	
		for(int j=qual ; j<(wy+1-qual) ; j++){	
			if(place11[i][j]->typeg==choose){
			int los;
			int w=0;
			int z=0;
			int l=0;
			int high=0;
			int mod=0;

			for(int wys=-qual ; wys<(qual+1) ; wys++){
				for(int szer=-qual ; szer < (qual+1) ; szer++){
					
					if(place11[i+wys][j+szer]->created==0){
							if(place11[i][j]->typeg==0) w++;
							if(place11[i][j]->typeg==1) z++;
							if(place11[i][j]->typeg==2) l++;
							high+=place11[i][j]->hight;
							mod++;
					}else{
					if(place11[i+wys][j+szer]->typeg==0) w++;
					if(place11[i+wys][j+szer]->typeg==1) z++;
					if(place11[i+wys][j+szer]->typeg==2) l++;
					high+=place11[i+wys][j+szer]->hight;
					mod++;
					}
				}
			}

			los=rand()%mod;
			los++;

			if(los>0 && los<=w) place11[i][j]->typeg=0;			
			if(los>w && los<=(w+z)) place11[i][j]->typeg=1;
			if(los>(w+z) && los<=(w+z+l)) place11[i][j]->typeg=2;
			place11[i][j]->hight=(high/mod);
			
			
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

					int type;
					type=getTextureType(tx,ty);
					
					if(type==0){					
						color[0]=0;
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
        fclose(fp);


}


int World::getTextureType(int x, int y){
		int type;
			if(x<=500){
				if(y<=500){
					type = place11[y][x]->typeg;
				}
				if(y>500){
					if(y<=500)type = place11[y][x]->typeg;
					if(y>500)type = place21[y-500][x]->typeg;
				}
			}

			if(x>500){
				if(y<=500){
					if(x<=500)type = place11[y][x]->typeg;
					if(x>500)type = place12[y][x-500]->typeg;
				}
				if(y>500){
					if(x<=500){
					if(x<=500)type = place11[y][x]->typeg;
					if(x>500)type = place12[y][x-500]->typeg;
					}else{
					if(x<=500)type = place21[y-500][x]->typeg;
					if(x>500)type = place22[y-500][x-500]->typeg;
					}
				}
			}

			return type;
}