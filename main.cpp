#include "TXLib.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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
  HDC pic;


};

struct Text
{
  string words = "";
  COLORREF cvet = TX_BLACK;
  int size;
  int x = 0;
  int y = 0;

};

struct Link
{
  string txt = "";
  string href = "";
  int x0 = 0;
  int y0 = 0;

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
  int aCount=0;
  int imgCount = 0;
  int pCount = 0;


};

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
    Save block[20];
    int b_i = 0;
    int a = 0;
    Save Img[5];
    Save Text[20];
    Save Link[20];
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
    txRectangle(1265, 230, 1435, 280);
    txRectangle(1265, 300, 1435, 350);
    txRectangle(1265, 370, 1435, 420);
    txRectangle(1265, 440, 1435, 490);
    txRectangle(1265, 510, 1435, 560);
    txRectangle(1265, 640, 1435, 690);
    txRectangle(1265, 710, 1435, 760);
    txLine(1200, 0, 1200, 800);
    txDrawText(1265, 20, 1435, 70, "Шапка");
    txDrawText(1265, 90, 1435, 140, "Блок");
    txDrawText(1265, 160, 1435, 210, "Колонка");
    txDrawText(1265, 230, 1435, 280, "Ссылка");
    txDrawText(1265, 300, 1435, 350, "Картинка");
    txDrawText(1265, 370, 1435, 420, "Текст");
    txDrawText(1265, 440, 1435, 490, "Содержимое");
    txDrawText(1265, 510, 1435, 560, "Подвал");
    txDrawText(1265, 640, 1435, 690, "Сохранить проект"); //неиспользован
    txDrawText(1265, 710, 1435, 760, "Конвертировать"); //неиспользован



    for(int i = 0; i < 20; i++)

    if (block[i].visible)
    {
    txSetFillColour(block[i].light);
    txRectangle(block[i].x1, block[i].y1, block[i].x2, block[i].y2);
    txDrawText(block[i].x1, block[i].y1, block[i].x2, block[i].y2, block[i].name);


   /* for(int i1 = 0; i1 < aCount; i1++)
    txTextOut(block[i].p[i1].x1,block[i].p[i1].y1,block[i].p[i1].words.c_str());


    for(int i2 = 0; i                                                                                                                                                                                                                                                                                                                                                                                                                                                                                < aCount; i1++)
    txTextOut(block[i].p[i1].x1,block[i].p[i1].y1,block[i].p[i1].words.c_str());

        */
    }




    txSetFillColour(TX_BLACK);
    txRectangle(block[b_i].x1, block[b_i].y1, block[b_i].x2, block[b_i].y2);


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
      txDrawText(block[b_i].x1, block[b_i].y1, block[b_i].x2, block[b_i].y2, "Шапка");
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
      txDrawText(block[b_i].x1, block[b_i].y1, block[b_i].x2, block[b_i].y2, "p");
      block[b_i].name = "p";
      block[b_i].cvet = "red";
      block[b_i].light = TX_RED;
      block[b_i].visible = true;
      b_i++;
    }


    if (click (1265, 230, 1435, 280))
    {
     txDrawText(block[b_i].x1, block[b_i].y1, block[b_i].x2, block[b_i].y2, "a");
     block[b_i].name = "a";
     block[b_i].cvet = "yellow";
     block[b_i].light = TX_YELLOW;
     block[b_i].visible = true;
     b_i++;
    }

    if (click (1265, 300, 1435, 350))
    {
     txDrawText(block[b_i].x1, block[b_i].y1, block[b_i].x2, block[b_i].y2, "img");
     block[b_i].name = "img";
     block[b_i].cvet = "brown";
     block[b_i].light = TX_BROWN;
     block[b_i].visible = true;
     b_i++;
    }

    if (click (1265, 370, 1435, 420))
    {
     txDrawText(block[b_i].x1, block[b_i].y1, block[b_i].x2, block[b_i].y2, "text");
     block[b_i].name = "text";
     block[b_i].cvet = "pink";
     block[b_i].light = TX_PINK;
     block[b_i].visible = true;
     b_i++;
    }

    if (click (1265, 440, 1435, 490))
    {
     txDrawText(block[b_i].x1, block[b_i].y1, block[b_i].x2, block[b_i].y2, "Содержимое");
     block[b_i].name = "Содержимое";
     block[b_i].visible = true;
     b_i++;
    }

    if (click (1265, 510, 1435, 560))
    {
     txDrawText(block[b_i].x1, block[b_i].y1, block[b_i].x2, block[b_i].y2, "Подвал");
     block[b_i].name = "Подвал";
     block[b_i].visible = true;
     b_i++;
    }

    if (click (1265, 710, 1435, 760))
    {
     ofstream fileSave("document.html");
     for (int i = 0; i < 20; i++)
     {

     if (block[i].visible)
     {
     fileSave << "<"<< block[i].name  << " style='background:" << block[i].cvet<<"; width:" << block[i].x2 - block[i].x1<<"px;";
     fileSave << "height:"<< block[i].y2 - block[i].y1 << "px; position:absolute; left:"<<block[i].x1<<"px; top:"<< block[i].y1<<"px'>\n"  << std::endl;
     fileSave << "</"<< block[i].name  <<" >" << std::endl;
     }
     }

    /* fileSave << "Координаты" << std::endl;
     fileSave << block[b_i].x1 << std::endl;
     fileSave << block[b_i].y1 << std::endl;
     fileSave << block[b_i].x2 << std::endl;
     fileSave << block[b_i].y2 << std::endl;
     fileSave << block[b_i].name << std::endl;
     fileSave << block[b_i].light << std::endl; */
     fileSave.close();

     txMessageBox("Проект конвертирован");

    }

    }

    txSleep(100);
    txEnd;

}

    return 0;
    }

