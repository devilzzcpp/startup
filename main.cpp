#include <iostream>
#include "TXLib.h"
#include <string>
#include <ctime>
#include "MyTimer.h"
#include "cross.h"

using namespace std;
HDC glock=txLoadImage ("gun1.2.bmp");
//HDC akl=txLoadImage ("47л.bmp");
HDC loc1=txLoadImage("local1.1.bmp");
HDC loc2=txLoadImage("local2.bmp");
HDC loc3=txLoadImage("local3.bmp");
HDC blood=txLoadImage("bloods1.bmp");
int rr1;
int map1=0;
int map2=0;
int map3=0;
//HDC ter1=txLoadImage ("враг1.bmp");
int x=100, y=100, x2=150, y2=300;
int w2, h2;
int o2, j2;
int timer1=0;
int col_bots=0;
int  ax, ay, ar ;





class buttons
{
private:
    int x2, y2;
    const char* name_char;

public:
    int x, y;
    int width, height;
    COLORREF cvet;
    COLORREF cvetText = TX_WHITE;
    string name;

    int draw(int x1, int y1, int w, int h,COLORREF c, string s)
    {
        x = x1;
        y = y1;
        width = w;
        height = h;
        cvet = c;
        name = s;
        name_char = name.c_str();//перевод стринг в конст чар
        x2 = x + width;
        y2 = y + height;
        txSetFillColour(cvet);
        txSetColour(cvetText);
        txRectangle(x, y, x2, y2);
        txDrawText(x, y, x2, y2, name_char);
        return 0;

    }

    int click()
    {
        if (txMouseButtons() == 1)
            if (txMouseX() > x && txMouseY() > y && txMouseX() < x2 && txMouseY() < y2)
                //txMessageBox("Click Button");
                return 1;
        return 0;
    }
};

class bot
{
public:

 int x, y;
 int w, h;
 int o, j;

string img_file;
HDC img;//=txLoadImage ("враг1.bmp");

bot(int x1, int y1, int w1, int h1, int o1, int j1, string img_file)
{const char*name;

 x=x1;
 y=y1;
 w=w1;
 h=h1;
 o=o1;
 j=j1;



name=img_file.c_str();
img=txLoadImage(name);
}

int Draw()
{
  txTransparentBlt(txDC(), x, y, w, h, img, o, j, TX_WHITE);

   return 0;
   }

int kick(int x1,int y1)
{


  if (x1 > x && y1 > y && x1 < x+94 && y1 < y+176)
  return 1;

  return 0;
  }


int run()
{
  int sd=rand() %4-2;
  x=x+sd;

 int sd1=rand() %20-20;
 txSleep(20+sd1);
}

//int attack()
//{
//ax=x+30;
//ay=y+50;
//ar=25;
//txSetFillColor(TX_WHITE);
//txCircle(ax, ay, ar);
//return 0;

  //}
  }   ;

int main()
{
 int xf, yf;
 int timer_begin=1;
 int timer_min, timer_sec;
 txCreateWindow (1400, 800);

 bot larry(800, 410, 160, 234, 0, 0,"bot2.1.bmp");
 col_bots++;

 bot Fedya(400, 390, 130, 210, 0, 0, "bot6.bmp");
 col_bots++;

 bot Oleg(500, 500, 140, 210, 0, 0, "bot3.1.bmp");

  txPlaySound("underground.wav");//проигрывание музыки


 cross cr1("прицел.bmp", 30, 30);


    buttons knopka1;
    buttons knopka2;
    buttons knopka3;
    buttons knopka4;

    int sprite=0;





while(1)
{
 txBegin();
 txSetFillColor(TX_BLACK);
 txClear();


  if(sprite==0) {
        knopka1.draw(475, 300, 450, 60, TX_DARKGRAY, "START");

        knopka2.draw(475, 400, 450, 60, TX_DARKGRAY, "SETTINGS");

       if (knopka1.click()==1) {sprite=1;}
       if (knopka2.click()==1) {sprite=2;}
         }
 txTextCursor();

  SYSTEMTIME t;
  GetLocalTime(&t);

  if(sprite==2){
   knopka3.draw(475, 300, 450, 60, TX_DARKGRAY, "CROSS'S COLOR");
   knopka4.draw(475, 500, 450, 60, TX_DARKGRAY, "YOUR GUN");
   //if (knopka3.click()==1) {}

  }

if(sprite==1) {

//if(GetAsyncKeyState(VK_UP)) {map1=1; map2=0; map3=0;}
//if(GetAsyncKeyState(VK_RIGHT)) {map1=0; map2=1; map3=0;}
//if(GetAsyncKeyState(VK_LEFT)) {map1=0; map2=0; map3=1;}



 if (map1==0){txTransparentBlt(txDC(), 0, 0, 1400, 800, loc1, 0, 0);}
 if (map1==1){txTransparentBlt(txDC(), 0, 0, 1400, 800, loc2, 0, 0); }
 if (map1==2){txTransparentBlt(txDC(), 0, 0, 1400, 800, loc3, 0, 0);}
 //txTransparentBlt(txDC(), 0, 0 , 1400, 800, blood, 0,0, TX_WHITE);
 //if (col_bots==0) {map1=1;}
 //if (col_bots==0 & map1==1) {map1=2;}

 if (larry.x<-900 & Fedya.x<-900 ) {map1=1; Oleg.Draw(); Oleg.run(); col_bots++;}
 if (Oleg.x<-900) {map1=2;}


 larry.Draw();
 Fedya.Draw();





 if (map1==0){
 if (timer_begin) {timer_min=t.wMinute; timer_sec=t.wSecond;timer_begin=0;}
 if (timer(timer_min,timer_sec,7) && col_bots>0)
 {//larry.attack(); Fedya.attack();
 txTransparentBlt(txDC(), 0, 0 , 1400, 800, blood, 0,0, TX_WHITE); }     }







 if (map1==1){
 if (timer_begin) {timer_min=t.wMinute; timer_sec=t.wSecond;timer_begin=0;  }
 if (timer(timer_min,timer_sec,7)&& col_bots>0)
 {txTransparentBlt(txDC(), 0, 0 , 1400, 800, blood, 0,0, TX_WHITE);}     }






 cr1.moveMouse(txMouseX(), txMouseY());
 txTransparentBlt(txDC(), 588, 585, 224, 215, glock, 0, 0, TX_WHITE);







 if (txMouseButtons() == 1)
 {  xf=txMouseX();    yf=txMouseY()  ;
 if (larry.kick(xf,yf)){ larry.x=-1001;
 //col_bots--;
    }
 if (Fedya.kick(xf,yf)) {Fedya.x=-1001;
 //col_bots--;
  }
 if (Oleg.kick(xf,yf)) {Oleg.x=-1001;
 //col_bots--;
  }
}

 larry.run();
 Fedya.run();



//if (map1==0){txSetFillColor(TX_RED); txRectangle(200, 200, 300, 300); }
//for(int i=0; i<5; i=i+1){rr1=0; txSleep(rr1); rr1=rr1+1000;}
//if(rr1==1000){txSetFillColor(TX_RED); txRectangle(200, 200, 300, 300);}
 //txSleep(200);
}
  txEnd();


}


return 1;
return 0;



}
