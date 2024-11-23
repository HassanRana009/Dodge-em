//============================================================================
// Name        : game.cpp
// Author      : Muhammad Hassan Rana
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Dodge 'Em...
//============================================================================

#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include<time.h>
#include<fstream>//for file handling
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
int level=1;
int P=2;
int menu=0;
int score=0;
// Drawing opponent car 1

float OOPx = 20; 
float OOPy = 100; 
float width = 8; 
float height = 7;
float* color = colors[BLUE_VIOLET]; 
float radius = 3.0;

void OpponentCar(float OOPx,float OOPy)
{	DrawRoundRect(OOPx,OOPy,width,height,color,radius); // bottom left tyre
	DrawRoundRect(OOPx+width*3,OOPy,width,height,color,radius); // bottom right tyre
	DrawRoundRect(OOPx+width*3,OOPy+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(OOPx,OOPy+height*4,width,height,color,radius); // top left tyre 
	DrawRoundRect(OOPx, OOPy+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(OOPx+width, OOPy+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(OOPx+width*3, OOPy+height*2, width, height, color, radius/2); // body right rect
}

//Drawing Opponent Car 2
float OOPx1 = 30; 
float OOPy1 = 720; 
float width11 = 8; 
float height11 = 7;
float* color11 = colors[BLUE_VIOLET]; 
float radius11 = 3.0;

void OpponentCar1(float OOPx1,float OOPy1)
{	DrawRoundRect(OOPx1,OOPy1,width11,height11,color11,radius11); // bottom left tyre
	DrawRoundRect(OOPx1+width11*3,OOPy1,width11,height11,color11,radius11); // bottom right tyre
	DrawRoundRect(OOPx1+width11*3,OOPy1+height11*4,width11,height11,color11,radius11); // top right tyre
	DrawRoundRect(OOPx1,OOPy1+height11*4,width11,height11,color11,radius11); // top left tyre 
	DrawRoundRect(OOPx1, OOPy1+height11*2, width11, height11, color11, radius11/2); // body left rect
	DrawRoundRect(OOPx1+width11, OOPy1+height11, width11*2, height11*3, color11, radius11/2); // body center rect
	DrawRoundRect(OOPx1+width11*3, OOPy1+height11*2, width11, height11, color11, radius11/2); // body right rect
}
//Movement in loops

void MovementOpponentCar2()
{
//Cirlce1 for Car1
 
if(OOPx<780 && OOPy==100)
   OOPx+=5;

if(OOPx==780 && OOPy<720)
   OOPy+=5;

if(OOPx>30 && OOPy==720)
   OOPx-=5;

if(OOPx==30 && OOPy>100)
   OOPy-=5;

//Cirlce1 for Car2
 
if(OOPx1<780 && OOPy1==100)
   OOPx1+=5;

if(OOPx1==780 && OOPy1<720)
   OOPy1+=5;

if(OOPx1>30 && OOPy1==720)
   OOPx1-=5;

if(OOPx1==30 && OOPy1>100)
   OOPy1-=5;
//Cirlce2 For Car1

if(OOPx==90 && (OOPy<=650 && OOPy>160))
   OOPy-=5;

if((OOPx>=90 && OOPx<720) && OOPy==160)
   OOPx+=5;

if(OOPx==720 && (OOPy>=160 && OOPy<650))
   OOPy+=5;

if((OOPx<=720 && OOPx>90) && OOPy==650)
   OOPx-=5;
//Cirlce2 For Car2

if(OOPx1==90 && (OOPy1<=650 && OOPy1>160))
   OOPy1-=5;

if((OOPx1>=90 && OOPx1<720) && OOPy1==160)
   OOPx1+=5;

if(OOPx1==720 && (OOPy1>=160 && OOPy1<650))
   OOPy1+=5;

if((OOPx1<=720 && OOPx1>90) && OOPy1==650)
   OOPx1-=5;
//Circle3 For Car

if(OOPx==150 && (OOPy<=590 && OOPy>230))
   OOPy-=5;

if((OOPx>=150 && OOPx<650) && OOPy==230)
   OOPx+=5;

if(OOPx==650 && (OOPy>=230 && OOPy<590))
   OOPy+=5;

if((OOPx<=650 && OOPx>150) && OOPy==590)
   OOPx-=5;


//Circle3 For Car2

if(OOPx1==150 && (OOPy1<=590 && OOPy1>230))
   OOPy1-=5;
if((OOPx1>=150 && OOPx1<650) && OOPy1==230)
   OOPx1+=5;
if(OOPx1==650 && (OOPy1>=230 && OOPy1<590))
   OOPy1+=5;
if((OOPx1<=650 && OOPx1>150) && OOPy1==590)
   OOPx1-=5;
//Circle4 For Car1

if(OOPx==220 && (OOPy<=520 && OOPy>290))
   OOPy-=5;

if((OOPx>=220 && OOPx<590) && OOPy==290)
   OOPx+=5;

if(OOPx==590 && ( OOPy>=290 && OOPy<520))
   OOPy+=5;

if((OOPx<=590 && OOPx>220) && OOPy==520)
   OOPx-=5;


//Circle4 For Car2

if(OOPx1==220 && (OOPy1<=520 && OOPy1>290))
   OOPy1-=5;

if((OOPx1>=220 && OOPx1<590) && OOPy1==290)
   OOPx1+=5;

if(OOPx1==590 && ( OOPy1>=290 && OOPy1<520))
   OOPy1+=5;

if((OOPx1<=590 && OOPx1>220) && OOPy1==520)
   OOPx1-=5;
}
//Movement in loops
void MovementOpponentCar()
{
//Cirlce1
 
if(OOPx<780 && OOPy==100)
   OOPx+=5;

if(OOPx==780 && OOPy<720)
   OOPy+=5;

if(OOPx>30 && OOPy==720)
   OOPx-=5;

if(OOPx==30 && OOPy>100)
   OOPy-=5;

//Cirlce2

if(OOPx==90 && (OOPy<=650 && OOPy>160))
   OOPy-=5;

if((OOPx>=90 && OOPx<720) && OOPy==160)
   OOPx+=5;

if(OOPx==720 && (OOPy>=160 && OOPy<650))
   OOPy+=5;

if((OOPx<=720 && OOPx>90) && OOPy==650)
   OOPx-=5;
//Circle3

if(OOPx==150 && (OOPy<=590 && OOPy>230))
   OOPy-=5;

if((OOPx>=150 && OOPx<650) && OOPy==230)
   OOPx+=5;

if(OOPx==650 && (OOPy>=230 && OOPy<590))
   OOPy+=5;

if((OOPx<=650 && OOPx>150) && OOPy==590)
   OOPx-=5;

//Circle4

if(OOPx==220 && (OOPy<=520 && OOPy>290))
   OOPy-=5;

if((OOPx>=220 && OOPx<590) && OOPy==290)
   OOPx+=5;

if(OOPx==590 && ( OOPy>=290 && OOPy<520))
   OOPy+=5;

if((OOPx<=590 && OOPx>220) && OOPy==520)
   OOPx-=5;
}
//Movement in loops1
void MovementOpponentCar1()
{
//Cirlce1
 
if(OOPx<780 && OOPy==100)
   OOPx+=10;

if(OOPx==780 && OOPy<720)
   OOPy+=10;

if(OOPx>30 && OOPy==720)
   OOPx-=10;

if(OOPx==30 && OOPy>100)
   OOPy-=10;

//Cirlce2

if(OOPx==90 && (OOPy<=650 && OOPy>160))
   OOPy-=10;

if((OOPx>=90 && OOPx<720) && OOPy==160)
   OOPx+=10;

if(OOPx==720 && (OOPy>=160 && OOPy<650))
   OOPy+=10;

if((OOPx<=720 && OOPx>90) && OOPy==650)
   OOPx-=10;
//Circle3

if(OOPx==150 && (OOPy<=590 && OOPy>230))
   OOPy-=10;

if((OOPx>=150 && OOPx<650) && OOPy==230)
   OOPx+=10;

if(OOPx==650 && (OOPy>=230 && OOPy<590))
   OOPy+=10;

if((OOPx<=650 && OOPx>150) && OOPy==590)
   OOPx-=10;

//Circle4

if(OOPx==220 && (OOPy<=520 && OOPy>290))
   OOPy-=10;

if((OOPx>=220 && OOPx<590) && OOPy==290)
   OOPx+=10;

if(OOPx==590 && ( OOPy>=290 && OOPy<520))
   OOPy+=10;

if((OOPx<=590 && OOPx>220) && OOPy==520)
   OOPx-=10;
}
//Random turn
int turn;
void Turn1()
{
//Move up 
if(OOPx==400 && OOPy==100)
{
 turn=rand()% 2;
if(turn==1)
 OOPy=160;
}

if(OOPx==400 && OOPy==160)
{
 turn=rand()% 3;
 if(turn==1)
    OOPy=230;
 if(turn==2)
    OOPy=100;
}

if(OOPx==400 && OOPy==230)
{
 turn=rand()% 3;
 if(turn==1)
    OOPy=290;
 if(turn==2)
    OOPy=160;
}

if(OOPx==400 && OOPy==290)
{
 turn=rand()% 2;
 if(turn==1)
    OOPy=230;
}
/*
//Move Left
if(x==780 && y==400)
{
 turn=rand()% 2;
 if(turn==1)
    x=720;
}

if(x==720 && y==400)
{
  turn=rand()% 3;
  if(turn==1)
     x=650;
  if(turn==2)
     x=780;
}

if(x==650 && y==400)
{
 turn=rand()% 3;
 if(turn==1)
    x=590;
 if(turn==2)
    x=720;
}

if(x==590 && y==400)
{
 turn=rand()% 2;
 if(turn==1)
    x=650;
}
*/
//Move Down
if(OOPx==400 && OOPy==720)
{
 turn=rand()% 2;
 if(turn==1)
 OOPy=650;
}   

if(OOPx==400 && OOPy==650)
{
  turn=rand()% 3;
  if(turn==1)
     OOPy=590;
  if(turn==2)
     OOPy=720;
}

if(OOPx==400 && OOPy==590)
{
  turn=rand()% 3;
  if(turn==1)
     OOPy=520;
  if(turn==2)
     OOPy=650;
}

if(OOPx==400 && OOPy==520)
{
   turn=rand()% 2;
   if(turn==1)
      OOPy=590;
}
/*
//Move Right
if(x==30 && y==400)
{
  turn=rand()% 2;
  if(turn==1)
   x=90;
}

if(x==90 && y==400)
{
  turn=rand()% 3;
  if(turn==1)
     x=150;
  if(turn==2)
     x=30;
}

if(x==150 && y==400)
{
  turn=rand()% 3;
  if(turn==1)
     x=220;
  if(turn==2)
     x=90;
}

if(x==220 && y==400)
{
  turn=rand()% 2;
  if(turn==1)
     x=150;
}
*/
}



//Random turn2
void Turn2()
{
//Move up 
if(OOPx==400 && OOPy==100)
{
 turn=rand()% 2;
if(turn==1)
 OOPy=160;
}

if(OOPx==400 && OOPy==160)
{
 turn=rand()% 3;
 if(turn==1)
    OOPy=230;
 if(turn==2)
    OOPy=100;
}

if(OOPx==400 && OOPy==230)
{
 turn=rand()% 3;
 if(turn==1)
    OOPy=290;
 if(turn==2)
    OOPy=160;
}

if(OOPx==400 && OOPy==290)
{
 turn=rand()% 2;
 if(turn==1)
    OOPy=230;
}

//Move Left
if(OOPx==780 && OOPy==400)
{
 turn=rand()% 2;
 if(turn==1)
    OOPx=720;
}

if(OOPx==720 && OOPy==400)
{
  turn=rand()% 3;
  if(turn==1)
     OOPx=650;
  if(turn==2)
     OOPx=780;
}

if(OOPx==650 && OOPy==400)
{
 turn=rand()% 3;
 if(turn==1)
    OOPx=590;
 if(turn==2)
    OOPx=720;
}

if(OOPx==590 && OOPy==400)
{
 turn=rand()% 2;
 if(turn==1)
    OOPx=650;
}

//Move Down
if(OOPx==400 && OOPy==720)
{
 turn=rand()% 2;
 if(turn==1)
 OOPy=650;
}   

if(OOPx==400 && OOPy==650)
{
  turn=rand()% 3;
  if(turn==1)
     OOPy=590;
  if(turn==2)
     OOPy=720;
}

if(OOPx==400 && OOPy==590)
{
  turn=rand()% 3;
  if(turn==1)
     OOPy=520;
  if(turn==2)
     OOPy=650;
}

if(OOPx==400 && OOPy==520)
{
   turn=rand()% 2;
   if(turn==1)
      OOPy=590;
}

//Move Right
if(OOPx==30 && OOPy==400)
{
  turn=rand()% 2;
  if(turn==1)
   OOPx=90;
}

if(OOPx==90 && OOPy==400)
{
  turn=rand()% 3;
  if(turn==1)
     OOPx=150;
  if(turn==2)
     OOPx=30;
}

if(OOPx==150 && OOPy==400)
{
  turn=rand()% 3;
  if(turn==1)
     OOPx=220;
  if(turn==2)
     OOPx=90;
}

if(OOPx==220 && OOPy==400)
{
  turn=rand()% 2;
  if(turn==1)
     OOPx=150;
}

}


//Random turn3
int turn11;
void Turn3()
{
//Move up 
if(OOPx1==400 && OOPy1==100)
{
 turn11=rand()% 2;
if(turn11==1)
 OOPy1=160;
}

if(OOPx1==400 && OOPy1==160)
{
 turn11=rand()% 3;
 if(turn11==1)
    OOPy1=230;
 if(turn11==2)
    OOPy1=100;
}

if(OOPx1==400 && OOPy1==230)
{
 turn11=rand()% 3;
 if(turn11==1)
    OOPy1=290;
 if(turn11==2)
    OOPy1=160;
}
if(OOPx1==400 && OOPy1==290)
{
 turn11=rand()% 2;
 if(turn11==1)
    OOPy1=230;
}

//Move Left
if(OOPx1==780 && OOPy1==400)
{
 turn11=rand()% 2;
 if(turn11==1)
    OOPx1=720;
}

if(OOPx1==720 && OOPy1==400)
{
  turn11=rand()% 3;
  if(turn11==1)
     OOPx1=650;
  if(turn11==2)
     OOPx1=780;
}

if(OOPx1==650 && OOPy1==400)
{
 turn11=rand()% 3;
 if(turn11==1)
    OOPx1=590;
 if(turn11==2)
    OOPx1=720;
}

if(OOPx1==590 && OOPy1==400)
{
 turn11=rand()% 2;
 if(turn11==1)
    OOPx1=650;
}
//Move Down
if(OOPx1==400 && OOPy1==720)
{
 turn11=rand()% 2;
 if(turn11==1)
 OOPy1=650;
}   

if(OOPx1==400 && OOPy1==650)
{
  turn11=rand()% 3;
  if(turn11==1)
     OOPy1=590;
  if(turn11==2)
     OOPy1=720;
}

if(OOPx1==400 && OOPy1==590)
{
  turn11=rand()% 3;
  if(turn11==1)
     OOPy1=520;
  if(turn11==2)
     OOPy1=650;
}

if(OOPx1==400 && OOPy1==520)
{
   turn11=rand()% 2;
   if(turn11==1)
      OOPy1=590;
}

//Move Right
if(OOPx1==30 && OOPy1==400)
{
  turn11=rand()% 2;
  if(turn11==1)
   OOPx1=90;
}
if(OOPx1==90 && OOPy1==400)
{
  turn11=rand()% 3;
  if(turn11==1)
     OOPx1=150;
  if(turn11==2)
     OOPx1=30;
}

if(OOPx1==150 && OOPy1==400)
{
  turn11=rand()% 3;
  if(turn11==1)
     OOPx1=220;
  if(turn11==2)
     OOPx1=90;
}

if(OOPx1==220 && OOPy1==400)
{
  turn11=rand()% 2;
  if(turn11==1)
     OOPx1=150;
}

}
// Drawing Player car
float Px_1 = 400; 
float Py_1 = 720; 
float width_1 = 8; 
float height_1 = 7;
float* color_1 = colors[RED]; 
float radius_1 = 3.0;

void PlayerCar(float Px_1,float Py_1)
{
	DrawRoundRect(Px_1,Py_1,width_1,height_1,color_1,radius_1); // bottom left tyre
	DrawRoundRect(Px_1+width_1*3,Py_1,width_1,height_1,color_1,radius_1); // bottom right tyre
	DrawRoundRect(Px_1+width_1*3,Py_1+height_1*4,width_1,height_1,color_1,radius_1); // top right tyre
	DrawRoundRect(Px_1,Py_1+height_1*4,width_1,height_1,color_1,radius_1); // top left tyre
	DrawRoundRect(Px_1, Py_1+height_1*2, width_1, height_1, color_1, radius_1/2); // body left rect
	DrawRoundRect(Px_1+width_1, Py_1+height_1, width_1*2, height_1*3, color_1, radius_1/2); // body center rect
	DrawRoundRect(Px_1+width_1*3, Py_1+height_1*2, width_1, height_1, color_1, radius_1/2); // body right rect
}
void MovementPlayerCar()
{
//Cirlce1
 
if(Px_1<780 && Py_1==720)
   Px_1+=5;

if(Px_1==780 && Py_1>100)
   Py_1-=5;

if(Px_1>30 && Py_1==100)
   Px_1-=5;

if(Px_1==30 && Py_1<720)
   Py_1+=5;

//Cirlce2

if(Px_1==90 && (Py_1<=650 && Py_1>=160))
   Py_1+=5;

if((Px_1>=90 && Px_1<720) && Py_1==650)
   Px_1+=5;
if(Px_1==720 && (Py_1>=160 && Py_1<=650))
   Py_1-=5;

if((Px_1<=720 && Px_1>90) && Py_1==160)
   Px_1-=5;
//Circle3

if(Px_1==150 && (Py_1<=590 && Py_1>=230))
   Py_1+=5;

if((Px_1>=150 && Px_1<650) && Py_1==590)
   Px_1+=5;

if(Px_1==650 && (Py_1>=230 && Py_1<=590))
   Py_1-=5;

if((Px_1<=650 && Px_1>150) && Py_1==230)
   Px_1-=5;

//Circle4

if(Px_1==220 && (Py_1<=520 && Py_1>=290))
   Py_1+=5;
if((Px_1>=220 && Px_1<590) && Py_1==520)
   Px_1+=5;

if(Px_1==590 && ( Py_1>=290 && Py_1<=520))
   Py_1-=5;

if((Px_1<=590 && Px_1>220) && Py_1==290)
   Px_1-=5;

}
//FOOD
int foodPoints[5000][5000];

void Food()
{
 for(int i=120;i<350;i+=60)
 {
  float* _rcolor=colors[RED];
   for(int j=40;j<800;j+=65)
   {
     if(j>400)
     {
       DrawCircle(j+45+foodPoints[i][j],i+foodPoints[i][j],7,_rcolor);
     }
      else
        DrawCircle(j+foodPoints[i][j],i+foodPoints[i][j],7,_rcolor);
   }
  }


 for(int i=720;i>520;i-=60)
 {
  float* _rcolor=colors[RED];
   for(int j=40;j<800;j+=65)
   {
     if(j>400)
     {
       DrawCircle(j+45+foodPoints[i][j],i+foodPoints[i][j],7,_rcolor);
     }
      else
        DrawCircle(j+foodPoints[i][j],i+foodPoints[i][j],7,_rcolor);
   }
  }

}

//FOOD1
int foodPoints1[5000][5000];
void Food1()
{
 for(int i=120;i<350;i+=60)
 {
  float* __rcolor=colors[RED];
   for(int j=40;j<800;j+=65)
   {
     if(j>400)
     {
       DrawCircle(j+45+foodPoints1[i][j],i+foodPoints1[i][j],7,__rcolor);
     }
      else
        DrawCircle(j+foodPoints1[i][j],i+foodPoints1[i][j],7,__rcolor);
   }
  }


 for(int i=720;i>520;i-=60)
 {
  float* __rcolor=colors[RED];
   for(int j=40;j<800;j+=65)
   {
     if(j>400)
     {
       DrawCircle(j+45+foodPoints1[i][j],i+foodPoints1[i][j],7,__rcolor);
     }
      else
        DrawCircle(j+foodPoints1[i][j],i+foodPoints1[i][j],7,__rcolor);
   }
  }

}

//FOOD2
int foodPoints2[5000][5000];
void Food2()
{
 for(int i=120;i<350;i+=60)
 {
  float* __rcolor1=colors[RED];
   for(int j=40;j<800;j+=65)
   {
     if(j>400)
     {
       DrawCircle(j+45+foodPoints2[i][j],i+foodPoints2[i][j],7,__rcolor1);
     }
      else
        DrawCircle(j+foodPoints2[i][j],i+foodPoints2[i][j],7,__rcolor1);
   }
  }


 for(int i=720;i>520;i-=60)
 {
  float* __rcolor1=colors[RED];
   for(int j=40;j<800;j+=65)
   {
     if(j>400)
     {
       DrawCircle(j+45+foodPoints2[i][j],i+foodPoints2[i][j],7,__rcolor1);
     }
      else
        DrawCircle(j+foodPoints2[i][j],i+foodPoints2[i][j],7,__rcolor1);
   }
  }

}


//FOOD3
int foodPoints3[5000][5000];
void Food3()
{
 for(int i=120;i<350;i+=60)
 {
  float* __rcolor3=colors[RED];
   for(int j=40;j<800;j+=65)
   {
     if(j>400)
     {
       DrawCircle(j+45+foodPoints3[i][j],i+foodPoints3[i][j],7,__rcolor3);
     }
      else
        DrawCircle(j+foodPoints3[i][j],i+foodPoints3[i][j],7,__rcolor3);
   }
  }


 for(int i=720;i>520;i-=60)
 {
  float* __rcolor3=colors[RED];
   for(int j=40;j<800;j+=65)
   {
     if(j>400)
     {
       DrawCircle(j+45+foodPoints3[i][j],i+foodPoints3[i][j],7,__rcolor3);
     }
      else
        DrawCircle(j+foodPoints3[i][j],i+foodPoints3[i][j],7,__rcolor3);
   }
  }

}
//FOODEAT
void FoodEat()
{
 for(int i=120;i<350;i+=60)
 {
   for(int j=40;j<800;j+=65)
   {
     if(Px_1-j<35 && Px_1-j>-30 && Py_1-i<5 && Py_1-i>-30)
     {
       if(foodPoints[i][j]==0)
       {
        score++;
        foodPoints[i][j]+=1000;
       } 
     }
   }
 }


 for(int i=720;i>520;i-=60)
 {
   for(int j=40;j<800;j+=65)
   {
      if(Px_1-j<35 && Px_1-j>-30 && Py_1-i<5 && Py_1-i>-30)
     {
       if(foodPoints[i][j]==0)
       {
        score++;
        foodPoints[i][j]+=1000;
       } 
     }
   }
 }
}

//FOODEAT1
void FoodEat1()
{
 for(int i=120;i<350;i+=60)
 {
   for(int j=40;j<800;j+=65)
   {
     if(Px_1-j<35 && Px_1-j>-30 && Py_1-i<5 && Py_1-i>-30)
     {
       if(foodPoints1[i][j]==0)
       {
        score++;
        foodPoints1[i][j]+=1000;
       } 
     }
   }
 }
 for(int i=720;i>520;i-=60)
 {
   for(int j=40;j<800;j+=65)
   {
      if(Px_1-j<35 && Px_1-j>-30 && Py_1-i<5 && Py_1-i>-30)
     {
       if(foodPoints1[i][j]==0)
       {
        score++;
        foodPoints1[i][j]+=1000;
       } 
     }
   }
 }
}

//FOODEAT2
void FoodEat2()
{
 for(int i=120;i<350;i+=60)
 {
   for(int j=40;j<800;j+=65)
   {
     if(Px_1-j<35 && Px_1-j>-30 && Py_1-i<5 && Py_1-i>-30)
     {
       if(foodPoints2[i][j]==0)
       {
        score++;
        foodPoints2[i][j]+=1000;
       } 
     }
   }
 }


 for(int i=720;i>520;i-=60)
 {
   for(int j=40;j<800;j+=65)
   {
      if(Px_1-j<35 && Px_1-j>-30 && Py_1-i<5 && Py_1-i>-30)
     {
       if(foodPoints2[i][j]==0)
       {
        score++;
        foodPoints2[i][j]+=1000;
       } 
     }
   }
 }
}
//FOODEAT3
void FoodEat3()
{
 for(int i=120;i<350;i+=60)
 {
   for(int j=40;j<800;j+=65)
   {
     if(Px_1-j<35 && Px_1-j>-30 && Py_1-i<5 && Py_1-i>-30)
     {
       if(foodPoints3[i][j]==0)
       {
        score++;
        foodPoints3[i][j]+=1000;
       } 
     }
   }
 }
 for(int i=720;i>520;i-=60)
 {
   for(int j=40;j<800;j+=65)
   {
      if(Px_1-j<35 && Px_1-j>-30 && Py_1-i<5 && Py_1-i>-30)
     {
       if(foodPoints3[i][j]==0)
       {
        score++;
        foodPoints3[i][j]+=1000;
       } 
     }
   }
 }
}
//CRASH
int live=3;
void Crash()
{

 if(OOPx==Px_1 && OOPy==Py_1)
{
  OOPx=430;
  OOPy=100;

  Px_1=330;
  Py_1=100;
live--;
}

else if((OOPx-Px_1>-6 && OOPx-Px_1<6) && (OOPy-Py_1>-6 && OOPy-Py_1<6))
{
  OOPx=430;
  OOPy=100;

  Px_1=330;
  Py_1=100;
live--;
}
}
//CRASH1
void Crash1()
{

 if(OOPx1==Px_1 && OOPy1==Py_1)
{
  OOPx1=430;
  OOPy1=100;

  Px_1=330;
  Py_1=100;
live--;
}

else if((OOPx1-Px_1>-6 && OOPx1-Px_1<6) && (OOPy1-Py_1>-6 && OOPy1-Py_1<6))
{
  OOPx1=430;
  OOPy1=100;

  Px_1=330;
  Py_1=100;
live--;
}

}
//Storing HighScore
void StoreHighScore()
{
  ofstream myfile;
  myfile.open("highscores.txt", ios::out | ios::app);
  myfile<<score<<"\n";
  myfile.close();
  cout<<"Score Saved"<<endl;
}

//reading highscores from highscores.txt and storing them into an array
int highscore[10];
void HighScore()
{
 ifstream fin;
 string line;

 fin.open("highscores.txt");
 int i=0;

 while(fin)
 {
  getline(fin,line);

  if(i<10)
  {
    highscore[i]=stoi(line);
  }
   i++;
 }
  fin.close();
 
}
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
/*
 * Main Canvas drawing function.
 * */
//Board *b;
void GameDisplay()/**/{

	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	// calling some functions from util.cpp file to help students

	//Square at 400,20 position
	//DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Square at 250,250 position
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	//Display Score
	//Triangle at 300, 450 position
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	//Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//Circle at 50, 670 position
	//DrawCircle(50,670,10,colors[RED]);
	//Line from 550,50 to 550,480 with width 10
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	
	
        // Drawing Arena
        int gap_turn1 = 60;
	int sx1 = 20;
	int sy1 = 10;
	int swidth1 = 800/2 - gap_turn1/2; // half width
	int sheight1 = 10;
	float *scolor1 = colors[BROWN];
	DrawRectangle(sx1, sy1+65, swidth1, sheight1, scolor1); // bottom left
	DrawRectangle(sx1 + swidth1 + gap_turn1, sy1+65, swidth1 , sheight1, scolor1); // bottom right
	DrawRectangle(sx1+swidth1*2+gap_turn1, sy1+65+sheight1, sheight1*2, swidth1-65, scolor1); // right down
	DrawRectangle(sx1+swidth1*2+gap_turn1, sy1+sheight1+swidth1+gap_turn1, sheight1*2, swidth1-65, scolor1); // right up
	DrawRectangle(sx1 + swidth1 + gap_turn1, sy1+810-65, swidth1, sheight1, scolor1); // top left
	DrawRectangle(sx1, sy1+810-65, swidth1, sheight1, scolor1); // top right
	DrawRectangle(sx1-sheight1*2, sy1+sheight1+swidth1+gap_turn1, sheight1*2, swidth1-65, scolor1); // left up
	DrawRectangle(sx1-sheight1*2, sy1+65+sheight1, sheight1*2, swidth1-65, scolor1); // left down


        // Drawing Arena
        int gap_turn2 = 60;
	int sx2 = 20;
	int sy2 = 10;
	int swidth2 = 800/2 - gap_turn2/2; // half width
	int sheight2 = 10;
	float *scolor2 = colors[BROWN];
	DrawRectangle(sx2+65, sy2+130, swidth2-65, sheight2, scolor2); // bottom left
	DrawRectangle(sx2 + swidth2 + gap_turn2, sy2+130, swidth2-65 , sheight2, scolor2); // bottom right
	DrawRectangle(sx2-65+swidth2*2+gap_turn2, sy2+130+sheight2, sheight2*2, swidth2-130, scolor2); // right down
	DrawRectangle(sx2-65+swidth2*2+gap_turn2, sy2+sheight2+swidth2+gap_turn2, sheight2*2, swidth2-130, scolor2); // right up
	DrawRectangle(sx2 + swidth2 + gap_turn2, sy2+810-130, swidth2-65, sheight2, scolor2); // top left
	DrawRectangle(sx2+65, sy2+810-130, swidth2-65, sheight2, scolor2); // top right
	DrawRectangle(sx2+65-sheight2*2, sy2+sheight2+swidth2+gap_turn2, sheight2*2, swidth2-130, scolor2); // left up
	DrawRectangle(sx2+65-sheight2*2, sy2+130+sheight2, sheight2*2, swidth2-130, scolor2); // left down



        // Drawing Arena
        int gap_turn3 = 60;
	int sx3 = 20;
	int sy3 = 10;
	int swidth3 = 800/2 - gap_turn3/2; // half width
	int sheight3 = 10;
	float *scolor3 = colors[BROWN];
	DrawRectangle(sx3+130, sy3+195, swidth3-130, sheight3, scolor3); // bottom left
	DrawRectangle(sx3 + swidth3 + gap_turn3, sy3+195, swidth3-130 , sheight3, scolor3); // bottom right
	DrawRectangle(sx3-130+swidth3*2+gap_turn3, sy3+195+sheight3, sheight3*2, swidth3-195, scolor3); // right down
	DrawRectangle(sx3-130+swidth3*2+gap_turn3, sy3+sheight3+swidth3+gap_turn3, sheight3*2, swidth3-195, scolor3); // right up
	DrawRectangle(sx3 + swidth3 + gap_turn3, sy3+815-195, swidth3-130, sheight3, scolor3); // top left
	DrawRectangle(sx3+130, sy3+810-195, swidth3-130, sheight3, scolor3); // top right
	DrawRectangle(sx3+130-sheight3*2, sy3+sheight3+swidth3+gap_turn3, sheight3*2, swidth3-195, scolor3); // left up
	DrawRectangle(sx3+130-sheight3*2, sy3+195+sheight3, sheight3*2, swidth3-195, scolor3); // left down



        // Drawing Arena
        int gap_turn4 = 60;
	int sx4 = 20;
	int sy4 = 10;
	int swidth4 = 800/2 - gap_turn4/2; // half width
	int sheight4 = 10;
	float *scolor4 = colors[BROWN];
	DrawRectangle(sx4+195, sy4+260, swidth4-195, sheight4, scolor4); // bottom left
	DrawRectangle(sx4 + swidth4 + gap_turn4, sy4+260, swidth4-195 , sheight4, scolor4); // bottom right
	DrawRectangle(sx4-195+swidth4*2+gap_turn4, sy4+260+sheight4, sheight4*2, swidth4-260, scolor4); // right down
	DrawRectangle(sx4-195+swidth4*2+gap_turn4, sy4+sheight4+swidth4+gap_turn4, sheight4*2, swidth4-260, scolor4); // right up
	DrawRectangle(sx4 + swidth4 + gap_turn4, sy4+810-260, swidth4-195, sheight4, scolor4); // top left
	DrawRectangle(sx4+195, sy4+810-260, swidth4-195, sheight4, scolor4); // top right
	DrawRectangle(sx4+195-sheight4*2, sy4+sheight4+swidth4+gap_turn4, sheight4*2, swidth4-260, scolor4); // left up
	DrawRectangle(sx4+195-sheight4*2, sy4+260+sheight4, sheight4*2, swidth4-260, scolor4); // left down



        // Drawing Arena
        int gap_turn5 = 60;
	int sx5 = 20;
	int sy5 = 10;
	int swidth5 = 800/2 - gap_turn5/2; // half width
	int sheight5 = 10;
	float *scolor5 = colors[BROWN];
	DrawRectangle(sx5+260, sy5+325, swidth5-195, sheight5, scolor5); // bottom left
	DrawRectangle(sx5 + swidth5 + gap_turn5, sy5+325, swidth5-250 , sheight5, scolor5); // bottom right
	DrawRectangle(sx5-260+swidth5*2+gap_turn5, sy5+325+sheight5, sheight5*2, swidth5-263, scolor5); // right down
	DrawRectangle(sx5-260+swidth5*2+gap_turn5, sy5+sheight5+swidth5+gap_turn5, sheight5*2, swidth5-325, scolor5); // right up
	DrawRectangle(sx5 + swidth5 + gap_turn5, sy5+810-325, swidth5-250, sheight5, scolor5); // top left
	DrawRectangle(sx5+260, sy5+810-325, swidth5-195, sheight5, scolor5); // top right
	DrawRectangle(sx5+260-sheight5*2, sy5+sheight5+swidth5+gap_turn5, sheight5*2, swidth5-325, scolor5); // left up
	DrawRectangle(sx5+260-sheight5*2, sy5+325+sheight5, sheight5*2, swidth5-263, scolor5); // left down




	if(menu==1)
	{
	//LEVEL 1
        if(level==1)
	{
        
	DrawString( 30, 800, "Score=0"+std::to_string(score), colors[MISTY_ROSE]);
	DrawString( 720, 800, "LIVES ="+std::to_string(live), colors[MISTY_ROSE]);	
	DrawString( 380, 800, "Level ="+std::to_string(level), colors[MISTY_ROSE]);

	PlayerCar(Px_1,Py_1);
	OpponentCar(OOPx,OOPy);

	Crash();
	
	Food();
	FoodEat();

	if(P%2==0)
	{

	MovementPlayerCar();
	Turn1();
	
	MovementOpponentCar();
	

	}

	}
	if(score==96)
	{
 	level=2;
	}
	//LEVEL 2
	if(level==2)
	{

	DrawString( 30, 800, "Score=0"+std::to_string(score), colors[MISTY_ROSE]);
	DrawString( 720, 800, "LIVES ="+std::to_string(live), colors[MISTY_ROSE]);	
	DrawString( 380, 800, "Level ="+std::to_string(level), colors[MISTY_ROSE]);

	PlayerCar(Px_1,Py_1);
	OpponentCar(OOPx,OOPy);

	Crash();

	Food1();
	FoodEat1();

	if(P%2==0)
	{
 
	MovementPlayerCar();
	Turn2();
	
	MovementOpponentCar();
	
	}
	}

	if(score==192)
	{
	 level=3;
	}
	//LEVEL 3
	if(level==3)
	{
	DrawString( 30, 800, "Score=0"+std::to_string(score), colors[MISTY_ROSE]);
	DrawString( 720, 800, "LIVES ="+std::to_string(live), colors[MISTY_ROSE]);	
	DrawString( 380, 800, "Level ="+std::to_string(level), colors[MISTY_ROSE]);

	PlayerCar(Px_1,Py_1);
	OpponentCar(OOPx,OOPy);

	Crash();
	Food2();
	FoodEat2();

	if(P%2==0)
	{
 
	MovementPlayerCar();
	Turn2();
	
	MovementOpponentCar1();

	}
	}
	if(score==288)
	{
	 level=4;
	}
	
	//LEVEL 4
	if(level==4)
	{

	DrawString( 30, 800, "Score=0"+std::to_string(score), colors[MISTY_ROSE]);
	DrawString( 720, 800, "LIVES ="+std::to_string(live), colors[MISTY_ROSE]);	
	DrawString( 380, 800, "Level ="+std::to_string(level), colors[MISTY_ROSE]);

	PlayerCar(Px_1,Py_1);
	OpponentCar(OOPx,OOPy);
	OpponentCar1(OOPx1,OOPy1);

	Crash();
	Crash1();	
	Food3();
	FoodEat3();

	if(P%2==0)
	{
 
	MovementPlayerCar();
	Turn2();
	Turn3();
	
	MovementOpponentCar2();

	}
	}
	if(score==384)
	{
	 DrawSquare( 0 , 0 ,840,colors[GRAY]);
 	 DrawString( 320, 460, "YOU WON", colors[BLACK]);
	}
}
	StoreHighScore();


if(menu==4)
{
 DrawSquare( 0 , 0 ,840,colors[GRAY]);
 DrawString(300, 600,"High Score= "+std::to_string(score), colors[BLACK]);
}



if(menu==2)
{
 DrawSquare( 0 , 0 ,840,colors[GRAY]);
 DrawString( 110, 540, "To Pause Game Use 'P Key.' ", colors[BLACK]);
 DrawString( 110, 500, "To move Car through Sapces between Arena use Arrow Keys.", colors[BLACK]);
 DrawString( 110, 460, "Press 'UP Key' to move up and 'Down Key' to move downwards.", colors[BLACK]);
 DrawString( 110, 420, "Press 'Left Key' to move left and 'Right Key' to move right.", colors[BLACK]);
 DrawString( 110, 380, "You have to collect Food to gain Points And to move to next Level. ", colors[BLACK]);
 DrawString( 110, 340, "Have Fun While Playing the Game.", colors[BLACK]);
} 


if(menu==0)
{
  DrawSquare( 0 , 0 ,840,colors[WHITE]);
  DrawCircle(420,420,420,colors[GRAY]);
  DrawString( 310, 500, "Press '1' to Play Game", colors[BLACK]);
  DrawString( 310, 460, "Press '2' for Help", colors[BLACK]);
  DrawString( 310, 420, "Press '3' to Exit Game", colors[BLACK]);
  DrawString( 310, 380, "Use 'P' to Pause And Continue Game", colors[BLACK]);
  DrawString( 310, 340, "Press '0' to Display Menu", colors[BLACK]);
  DrawString( 310, 300, "Press '4' to Display High Score", colors[BLACK]);
}


if(live<1)
{ 
  menu=5;
if(menu==5)
{
 DrawSquare( 0 , 0 ,840,colors[GRAY]);
 DrawString( 310, 460, "GAME OVER", colors[BLACK]);
 DrawString( 170, 420, "Exit Game by Pressing 3 and Then Start Game again.", colors[BLACK]);
}
}


	glutPostRedisplay();
	glutSwapBuffers(); // do not modify this line.. or draw anything below this line
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		if(Px_1==780 && (Py_1<=450 && Py_1>=360))
		{
		Px_1=730;
		Px_1-=10;
		}
		else if(Px_1==720 &&  (Py_1<=450 && Py_1>=360))
		{
		Px_1=660;
		Px_1-=10;
		}
		else if(Px_1==650 &&  (Py_1<=450 && Py_1>=360))
		{
		Px_1=600;
		Px_1-=10;
		}
		else if(Px_1==220 &&  (Py_1<=450 && Py_1>=360))
		{
		Px_1=160;
		Px_1-=10;
		}
		else if(Px_1==150 &&  (Py_1<=450 && Py_1>=360))
		{
		Px_1=100;
		Px_1-=10;
		}
		else if(Px_1==90 &&   (Py_1<=450 && Py_1>=360))
		{
		Px_1=40;
		Px_1-=10;
		}
                cout<<"X:"<<Px_1<<endl;
	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		if(Px_1==30 && (Py_1<=450 && Py_1>=360))
		{
		Px_1=80;
		Px_1+=10;
		}
		else if(Px_1==90 && (Py_1<=450 && Py_1>=360))
		{
		Px_1=140;
		Px_1+=10;
		}
		else if(Px_1==150 && (Py_1<=450 && Py_1>=360))
		{
		Px_1=210;
		Px_1+=10;
		}
		else if(Px_1==590 && (Py_1<=450 && Py_1>=360))
		{
		Px_1=640;
		Px_1+=10;
		}
		else if(Px_1==650 && (Py_1<=450 && Py_1>=360))
		{
		Px_1=710;		
		Px_1+=10;
		}
		else if(Px_1==720 && (Py_1<=450 && Py_1>=360))
		{
		Px_1=770;
		Px_1+=10;
		}
		cout<<"X:"<<Px_1<<endl;
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		if((Px_1>=360 && Px_1<=450) && Py_1==100)
		{
		Py_1=150;
		Py_1+=10;
		}
		else if((Px_1>=360 && Px_1<=450) && Py_1==160)
		{
		Py_1=220;			
		Py_1+=10;
		}
		else if((Px_1>=360 && Px_1<=450) && Py_1==230)
		{
		Py_1=280;
		Py_1+=10;
		}
		else if((Px_1>=360 && Px_1<=450) && Py_1==520)
		{
		Py_1=580;
		Py_1+=10;
		}
		else if((Px_1>=360 && Px_1<=450) && Py_1==590)
		{
		Py_1=640;
		Py_1+=10;
		}
		else if((Px_1>=360 && Px_1<=450) && Py_1==650)
		{
		Py_1=710;
		Py_1+=10;
		}
                cout<<"Y:"<<Py_1<<endl;
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		if((Px_1>=360 && Px_1<=450) && Py_1==720)
		{
		Py_1=660;
		Py_1-=10;
		}
		else if((Px_1>=360 && Px_1<=450) && Py_1==650)
		{
		Py_1=600;
		Py_1-=10;
		}
		else if((Px_1>=360 && Px_1<=450) && Py_1==590)
		{
		Py_1=530;
		Py_1-=10;
		}
		else if((Px_1>=360 && Px_1<=450) && Py_1==290)
		{
		Py_1=240;
		Py_1-=10;
		}
		else if((Px_1>=360 && Px_1<=450) && Py_1==230)
		{
		Py_1=170;
		Py_1-=10;
		}
		else if((Px_1>=360 && Px_1<=450) && Py_1==160)
		{
		Py_1=110;
		Py_1-=10;
		}
		cout<<"Y:"<<Py_1<<endl;	
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/
	
	glutPostRedisplay();
}			

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27 || key== '3'/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == '0')
			{
		menu=0;

	}


	if (key == '1')
			{
		menu=1;

	}

if (key == '2')
			{
		menu=2;

	}

if (key == 'P' || key == 'p')
			{
		P+=1;

	}

if (key == '4')
			{
		menu=4;

	}


	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	HighScore();
	StoreHighScore();
        srand(time(0));
	for(int i=0; i<10;i++)
	cout<<highscore[i]<<endl;

	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 840, height = 840; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Centipede"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
