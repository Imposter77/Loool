#include "TXLib.h"

bool focus(int x, int y, int x2, int y2)
{
    if (txMouseX() >= x && txMouseX() <= x2 &&
        txMouseY() >= y && txMouseY() <= y2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool click(int x, int y, int x2, int y2)
{
    if (txMouseButtons() == 1 &&
        txMouseX() >= x && txMouseX() <= x2 &&
        txMouseY() >= y && txMouseY() <= y2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int funct(int x, int y)
{
  HDC k1 = txLoadImage("knopka23.bmp");
  HDC k2 = txLoadImage("knopka24.bmp");

  txTransparentBlt(txDC(),x,y,150,75, k1, 0, 0, TX_WHITE);
  txTransparentBlt(txDC(),x,y + 555,150,75, k2, 0, 0, TX_WHITE);

}


struct Pictures
{
  HDC pic;
}
;


int main()
{
    txCreateWindow (1200, 800);
    const char* PAGE = "Ãëàâíàÿ ñòðàíèöà";
    bool mneNadoelo = false;
    int x1 = 70;    int y1 = 125;
    int x2 = 450;
    int x3 = 850;
    mneNadoelo = false;
    HDC dom1 = txLoadImage("house1.bmp");
    HDC dom2 = txLoadImage("house2.bmp");
    HDC dom3 = txLoadImage("house3.bmp");
    HDC dom4 = txLoadImage("house4.bmp");
    HDC z1 = txLoadImage("zavod1.bmp");
    HDC z2 = txLoadImage("zavod2.bmp");
    HDC z3 = txLoadImage("zavod3.bmp");
    HDC z4 = txLoadImage("zavod4.bmp");

    txSetFillColour(TX_BLACK);

    while(!mneNadoelo)
    {
    Pictures knopka1;
    Pictures knopka2;
    Pictures knopka3;

    knopka1.pic = txLoadImage("knopka23.bmp");
    knopka2.pic = txLoadImage("knopka231.bmp");
    knopka3.pic = txLoadImage("knopka24.bmp");

    if (PAGE == "Ãëàâíàÿ ñòðàíèöà")
    {
       txBegin();
       txTransparentBlt(txDC(),50,55,150,75,knopka1.pic, 0, 0, TX_WHITE);
       txTransparentBlt(txDC(),450,55,150,75,knopka2.pic, 0, 0, TX_WHITE);
       txTransparentBlt(txDC(),50,600,150,75,knopka3.pic, 0, 0, TX_WHITE);
       txTransparentBlt(txDC(),450,600,150,75,knopka3.pic, 0, 0, TX_WHITE);
       txTransparentBlt(txDC(),650,55,150,75,knopka1.pic, 0, 0, TX_WHITE);


    if(click (50, 55, 200, 130))
    {
    txTransparentBlt(txDC(),x1,y1,100,80,dom1, 0, 0, TX_WHITE);
    txTransparentBlt(txDC(),x1,y1 + 100,100,80,dom2, 0, 0, TX_WHITE);
    txTransparentBlt(txDC(),x1,y1 + 200,105,84,dom3, 0, 0, TX_WHITE);
    txTransparentBlt(txDC(),x1,y1 + 300,100,83,dom4, 0, 0, TX_WHITE);
    }

    if(click (450, 55, 600, 130))
{
    txTransparentBlt(txDC(),x2,y1,125,83,z1, 0, 0, TX_WHITE);
    txTransparentBlt(txDC(),x2,y1 + 100,125,106,z2, 0, 0, TX_WHITE);
    txTransparentBlt(txDC(),x2,y1 + 230,165,69,z3, 0, 0, TX_WHITE);
    txTransparentBlt(txDC(),x2,y1 + 360,125,99,z4, 0, 0, TX_WHITE);
}

    if(click (650, 55, 1000, 130))
{
    txTransparentBlt(txDC(),x3,y1,125,83,z1, 0, 0, TX_WHITE);
    txTransparentBlt(txDC(),x3,y1 + 100,125,106,z2, 0, 0, TX_WHITE);
    txTransparentBlt(txDC(),x3,y1 + 230,125,69,z3, 0, 0, TX_WHITE);
    txTransparentBlt(txDC(),x3,y1 + 360,125,99,z4, 0, 0, TX_WHITE);
}

    if (click (50, 600, 200, 675))
    {
     txClear();

    }

    if (click (450, 600, 600, 675))
    {
     txClear();

    }

    if (click (850, 600, 1000, 675))
    {
     txClear();

    }

    funct(450, 200);


    if (click (70, 125, 800, 600))
    {
      txMouseButtons() == 1;
      txClear();
      txTransparentBlt(txDC(),txMouseX(),txMouseY(),100,80,dom1, 0, 0, TX_WHITE);

    }


    }

    if(GetAsyncKeyState(VK_ESCAPE))
    {
        mneNadoelo = true;
    }


        
    txSleep(2);
    txEnd();
    }


    return 0;
    cout<<"ghkg";
}

