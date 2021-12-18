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


};

struct Text
{
  string words = "";
  COLORREF cvet = TX_BLACK;
  int size;

};

struct Link
{
  string txt = "";
  string href = "";

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
    txDrawText(1265, 20, 1435, 70, "Логотип");
    txDrawText(1265, 90, 1435, 140, "Cтрока поиска");
    txDrawText(1265, 160, 1435, 210, "Телефон");
    txDrawText(1265, 230, 1435, 280, "Меню");
    txDrawText(1265, 300, 1435, 350, "Шапка");
    txDrawText(1265, 370, 1435, 420, "Левая колонка");
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
      txDrawText(100, 100, 200, 200, "Логотип");
      txDrawText(block[b_i].x1, block[b_i].y1, block[b_i].x2, block[b_i].y2, "Логотип");
      block[b_i].name = "Логотип";
     // block[b_i].light = TX_GREEN;
      block[b_i].visible = true;

      for(int i = 0; i < 20; i++)
      if (block[i].visible)
      b_i++;
      txSleep(100);
    }



    if (click (1265, 90, 1435, 140))
    {
      txDrawText(block[b_i].x1, block[b_i].y1, block[b_i].x2, block[b_i].y2, "Строка поиска");
      block[b_i].name = "Строка поиска";
      block[b_i].light = TX_BLUE;
      block[b_i].visible = true;
      b_i++;
    }

    if (click (1265, 160, 1435, 210))
    {
      txDrawText(block[b_i].x1, block[b_i].y1, block[b_i].x2, block[b_i].y2, "Телефон");
      block[b_i].name = "Телефон";
      block[b_i].light = TX_RED;
      block[b_i].visible = true;
      b_i++;
    }


    if (click (1265, 230, 1435, 280))
    {
     txDrawText(block[b_i].x1, block[b_i].y1, block[b_i].x2, block[b_i].y2, "Меню");
     block[b_i].name = "Меню";
     block[b_i].light = TX_YELLOW;
     block[b_i].visible = true;
     b_i++;
    }

    if (click (1265, 300, 1435, 350))
    {
     txDrawText(block[b_i].x1, block[b_i].y1, block[b_i].x2, block[b_i].y2, "Шапка");
     block[b_i].name = "Шапка";
     block[b_i].visible = true;
     b_i++;
    }

    if (click (1265, 370, 1435, 420))
    {
     txDrawText(block[b_i].x1, block[b_i].y1, block[b_i].x2, block[b_i].y2, "Левая колонка");
     block[b_i].name = "Левая колонка";
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

    if (click (1265, 640, 1435, 690))
    {
     ofstream fileSave("document.txt");

     fileSave << "Координаты" << std::endl;
     fileSave << block[b_i].x1 << std::endl;
     fileSave << block[b_i].y1 << std::endl;
     fileSave << block[b_i].x2 << std::endl;
     fileSave << block[b_i].y2 << std::endl;
     fileSave << block[b_i].name << std::endl;
     fileSave << block[b_i].light << std::endl;
     fileSave.close();
     txMessageBox ("Проект сохранён");
    }
    }

    txSleep(100);
    txEnd;

}

    return 0;
    }

