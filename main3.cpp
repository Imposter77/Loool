#include "TXLib.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int imgAddBool = 0;
int textAddBool = 0;
int aAddBool = 0;

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

struct Img
{
  string src = "";
  int weight = 0;
  int height = 0;
  int x = 0;
  int y = 0;
  HDC pic;


};



struct Text
{
  string words = "";
  COLORREF cvet = TX_BLACK;
  int size=10;
  int x = 0;
  int y = 0;

};



struct Link
{
  string txt = "";
  string href = "";
  COLORREF cvet = TX_PINK;
  int x = 0;
  int y = 0;

};



struct Save
{
  int x1 = 0;
  int y1 = 0;
  int x2 = 0;
  int y2 = 0;
  const char* name;
  COLORREF light = TX_BLACK;
  string cvet = "blue";
  bool visible = false;
  Link a[20];
  Img img[20];
  Text p[20];
  int aCount = 0;
  int imgCount = 0;
  int pCount = 0;


};
  Save block[20];
  int b_i = 0;

int Denis_add_img()
{
     const char* name = txInputBox ("Ââåäèòå íàçâàíèå ôàéëà", "System", "picture.bmp");

    while (!txMouseButtons() == 1);

        int x = 10,y = 10;
        x = txMouseX();
        y = txMouseY();
        HDC picter = txLoadImage(name);


        if (txMouseButtons() == 1)

        if (txMouseX() < 1200)
        {


        while (txMouseButtons() == 1)
        {
        x = txMouseX();
        y = txMouseY();
        }

       }
       txBitBlt(txDC(), x, y, 400, 400, picter);
        block[b_i-1].img[block[b_i-1].imgCount].pic = picter;

        imgAddBool=0;


        block[b_i-1].img[block[b_i-1].imgCount].src= name;
        block[b_i-1].img[block[b_i-1].imgCount].x=x;
        block[b_i-1].img[block[b_i-1].imgCount].y=y;

        block[b_i-1].imgCount++;
        txSleep(1000);
}

int Denis_add_text()
{
    int fontSize = 20;

     const char* name = txInputBox ("Ââåäèòå òåêñò", "System", "");

    while (!txMouseButtons() == 1);

        int x = 10,y = 10;
        x = txMouseX();
        y = txMouseY();

        txSelectFont ("Arial", 100);

        if(GetAsyncKeyState(1))  fontSize = 100;
        if(GetAsyncKeyState(2))  fontSize = 85;
        if(GetAsyncKeyState(3))  fontSize = 70;
        if(GetAsyncKeyState(4))  fontSize = 55;
        if(GetAsyncKeyState(5))  fontSize = 40;
        if(GetAsyncKeyState(6))  fontSize = 25;

        txSelectFont ("Arial", fontSize);


        if (txMouseButtons() == 1)

        if (txMouseX() < 1200)
        {


        while (txMouseButtons() == 1)
        {
        x = txMouseX();
        y = txMouseY();
        }

       }
       txTextOut (x, y, name);

        textAddBool = 0;

        block[b_i-1].p[block[b_i-1].pCount].words = name;
        block[b_i-1].p[block[b_i-1].pCount].size = fontSize;
        block[b_i-1].p[block[b_i-1].pCount].x = x;
        block[b_i-1].p[block[b_i-1].pCount].y = y;
        block[b_i-1].pCount++;

         txSelectFont ("Arial", 15);
         txSleep(1000);
}

int Denis_add_a()
{
     const char* name = txInputBox ("Ââåäèòå òåêñò ññûëêè", "System", "");
     const char* name1 = txInputBox ("Ââåäèòå ññûëêó", "System", "");

    while (!txMouseButtons() == 1);

           int x = 10, y = 10;

        x = txMouseX();
        y = txMouseY();





        if (txMouseButtons() == 1)

        if (txMouseX() < 1200)
        {


        while (txMouseButtons() == 1)
        {
        x = txMouseX();
        y = txMouseY();
        }

       }
       txTextOut (x,y,name);

        aAddBool = 0;
        //b_i++;

        block[b_i-1].a[block[b_i-1].aCount].txt = name;
        block[b_i-1].a[block[b_i-1].aCount].href = name1;
        block[b_i-1].a[block[b_i-1].aCount].x = x;
        block[b_i-1].a[block[b_i-1].aCount].y = y;
        block[b_i-1].aCount++;

        txSleep(1000);

}


int converHTML()
{

     ofstream fileSave("document.html");
     for (int i = 0; i < 20; i++)
     {

     if (block[i].visible)
     {
     fileSave << "<" << block[i].name << " style='background:" << block[i].cvet<<"; width:" << block[i].x2 - block[i].x1 << "px;";
     fileSave << "height:" << block[i].y2 - block[i].y1 << "px; position:absolute; left:"<< block[i].x1 <<"px; top:"<< block[i].y1 <<"px'>\n" << std::endl;

           for(int i1 = 0; i1 < block[i].imgCount; i1++)
           {

            fileSave << "<img src='"<< block[i].img[i1].src << "' style='float:left; margin-left:10px />\n";

            }

           for(int i1 = 0; i1 < block[i].pCount; i1++)
           {

            fileSave << "<p style='font-size:"<< block[i].p[i1].size<<"px;'>"<< block[i].p[i1].words << " </p>\n";

           }

            for(int i1 = 0; i1 < block[i].aCount; i1++)
           {

            fileSave << "<a href='"<< block[i].a[i1].href << "'>"<<block[i].a[i1].txt<<" </a>\n";

            }



        fileSave << "</"<< block[i].name  <<" >" << std::endl;
     }
     }

    /* fileSave << "Eii?aeiaou" << std::endl;
     fileSave << block[b_i].x1 << std::endl;
     fileSave << block[b_i].y1 << std::endl;
     fileSave << block[b_i].x2 << std::endl;
     fileSave << block[b_i].y2 << std::endl;
     fileSave << block[b_i].name << std::endl;
     fileSave << block[b_i].light << std::endl; */
     fileSave.close();

     txMessageBox("Ïðîåêò Êîíâåðòèðîâàí");
}


int main()
{

    txCreateWindow (1500, 800);
    bool mnenadoelo = false;
    txSetFillColour(TX_BLACK);
    txSetColour(TX_WHITE);
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
   // Save block[20];
    //int b_i = 0;
    int a = 0;
  //  Save Img[5];
   // Save Text[20];
   // Save Link[20];
    /*  setlocale(LC_ALL, "Russian");
    WIN32_FIND_DATAW wfd;
    HANDLE const hFind = FindFirstFileW(L"bin\\*", &wfd);
    if(INVALID_HANDLE_VALUE != hFind)
    {
      do {
      wcout << &wfd.cFileName[0] << endl;
      }
      while(NULL != FindNextFileW(hFind, &wfd));
      FindClose(hFind);
      system("pause");
    }      */



    while(!mnenadoelo)
    {

    txSetFillColour(TX_BLACK);
    txClear();
    txBegin;


    txRectangle(1265, 20, 1435, 70);
    txRectangle(1265, 90, 1435, 140);
    txRectangle(1265, 160, 1435, 210);
    txRectangle(1300, 230, 1435, 280);
    txRectangle(1300, 300, 1435, 350);
    txRectangle(1300, 370, 1435, 420);
    txRectangle(1265, 570, 1435, 620);
    txRectangle(1265, 640, 1435, 690);
    txRectangle(1265, 710, 1435, 760);
    txLine(1200, 0, 1200, 800);
    txDrawText(1265, 20, 1435, 70, "Çàãîëîâîê");
    txDrawText(1265, 90, 1435, 140, "Áëîê");

    txDrawText(1265, 160, 1435, 210, "Êîëîíêà");
    txDrawText(1300, 230, 1435, 280, "Ññûëêà");
    txDrawText(1300, 300, 1435, 350, "Êàðòèíêà");
    txDrawText(1300, 370, 1435, 420, "Òåêñò");

    txDrawText(1265, 570, 1435, 620, "Çàãðóçèòü");
    txDrawText(1265, 640, 1435, 690, "Êîíâåðòèðîâàòü");
    txDrawText(1265, 710, 1435, 760, "Ñîõðàíèòü ïðîåêò");
/*

Ã˜Ã Ã¯ÃªÃ 
"ÃÃ«Ã®Ãª"
"ÃŠÃ®Ã«Ã®Ã­ÃªÃ "
"Ã‘Ã±Ã»Ã«ÃªÃ "
ÃŠÃ Ã°Ã²Ã¨Ã­ÃªÃ 
Ã’Ã¥ÃªÃ±Ã²
Ã‘Ã®Ã¤Ã¥Ã°Ã¦Ã¨Ã¬Ã®Ã¥
ÃÃ®Ã¤Ã¢Ã Ã«"
Ã‘Ã®ÃµÃ°Ã Ã­Ã¨Ã²Ã¼ Ã¯Ã°Ã®Ã¥ÃªÃ²
ÃŠÃ®Ã­Ã¢Ã¥Ã°Ã²Ã¨Ã°Ã®Ã¢Ã Ã²Ã¼
*/
     int z;
    HDC picter1;


    HDC saveHDC = txCreateCompatibleDC (1200, 800);
    for(int i = 0; i < 20; i++)

    if (block[i].visible)
    {
    txSetFillColour(block[i].light);
    txRectangle(block[i].x1, block[i].y1, block[i].x2, block[i].y2);
    txDrawText(block[i].x1, block[i].y1, block[i].x2, block[i].y2, block[i].name);


        for(int i1 = 0; i1 < block[i].imgCount; i1++)
        {

           //picter1 = txLoadImage (block[i].img[i1].src);
        txBitBlt (saveHDC, block[i].x1, block[i].img[i1].y, 400, 400, block[i].img[i1].pic);
           //txDeleteDC (picter1);
        }

        if (block[i].imgCount)
        {
        txTransparentBlt (txDC(), 0, 0, 1200, 600, saveHDC, TX_BLACK);
        }


        for(int i1 = 0; i1 < block[i].pCount; i1++)
        {
        txSelectFont ("Arial",  block[i].p[i1].size);
        txTextOut (block[i].p[i1].x, block[i].p[i1].y,  block[i].p[i1].words.c_str());
        txSelectFont("Arial", 15);
        }

        for(int i1 = 0; i1 < block[i].aCount; i1++)
        {
        txSetColor(block[i].a[i1].cvet)  ;
        txTextOut (block[i].a[i1].x, block[i].a[i1].y,  block[i].a[i1].txt.c_str());
        txSetColor(TX_WHITE);
        }
   /* for(int i1 = 0; i1 < aCount; i1++)
    txTextOut(block[i].p[i1].x1,block[i].p[i1].y1,block[i].p[i1].words.c_str());
    for(int i2 = 0; i                                                                                                                                                                                                                                                                                                                                                                                                                                                                                < aCount; i1++)
    txTextOut(block[i].p[i1].x1,block[i].p[i1].y1,block[i].p[i1].words.c_str());
        */
    }

    txDeleteDC (saveHDC);


    txSetFillColour(TX_BLACK);
    txRectangle(block[b_i].x1, block[b_i].y1, block[b_i].x2, block[b_i].y2);

    if (imgAddBool)
    {
       Denis_add_img();
    }

    if (textAddBool)
    {
      Denis_add_text();
    }

    if (aAddBool)
    {
      Denis_add_a();
    }


      if (txMouseButtons() == 1)

         if (txMouseX() < 1200)
        {

          block[b_i].x1 = txMouseX();
          block[b_i].y1 = txMouseY();

        while (txMouseButtons() == 1)
        {
          block[b_i].x2 = txMouseX();
          block[b_i].y2 = txMouseY();
        }

        txSetFillColour(block[b_i].light);

        }

     else {

    if (click (1265, 20, 1435, 70))
    {
      txDrawText(100, 100, 200, 200, "Header");
      txDrawText(block[b_i].x1, block[b_i].y1, block[b_i].x2, block[b_i].y2, "Header");
      block[b_i].name = "header";
      block[b_i].light = TX_BLUE;
      block[b_i].cvet = "blue";
      block[b_i].visible = true;

      for(int i = 0; i < 20; i++)
      if (block[i].visible)
      b_i++;
      txSleep(100);
    }



    if (click (1265, 90, 1435, 140))
    {
      txDrawText(block[b_i].x1, block[b_i].y1, block[b_i].x2, block[b_i].y2, "div");
      block[b_i].name = "div";
      block[b_i].cvet = "green";
      block[b_i].light = TX_GREEN;
      block[b_i].visible = true;
      b_i++;
    }

    if (click (1265, 160, 1435, 210))
    {
      txDrawText(block[b_i].x1, block[b_i].y1, block[b_i].x2, block[b_i].y2, "aside");
      block[b_i].name = "aside";
      block[b_i].cvet = "red";
      block[b_i].light = TX_RED;
      block[b_i].visible = true;
      b_i++;
    }


    if (click (1265, 230, 1435, 280))
    {
      aAddBool = 1;
    }

    if (click (1265, 300, 1435, 350))
    {
     imgAddBool = 1;
    }

    if (click (1265, 370, 1435, 420))
    {
     textAddBool = 1;
    }

    if (click (1265, 640, 1435, 690))
    {
      converHTML();
    }

    if (click (1265, 710, 1435, 760))
    {
       converHTML();
    }

    }

    txSleep(100);
    txEnd;

}

    return 0;
    }
