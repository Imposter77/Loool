#include <iostream>
#include <fstream>
#include  <txlib.h>
#include  <string>
using namespace std;


 struct block
   {
 int x1 =0;
 int y1 = 0;
 int x2 = 0 ;
 int y2 = 0 ;

const char* name;

COLORREF light ;

bool visible=false  ;

 };

int save(string filename, block kvadrat)
{

       ofstream f (filename);




       kvadrat.name="newname";

          kvadrat.x1=400;
          kvadrat.y1=100;
          kvadrat.x2=300;
          kvadrat.y2=300;
          kvadrat.light=TX_RED;
          kvadrat.visible = true;
          txSetFillColor(kvadrat.light);
          txRectangle(kvadrat.x1,kvadrat.y1,kvadrat.x2,kvadrat.y2);

       //1 картинка


       f<< kvadrat.name<<"\n";
       f<<kvadrat.x1<<"\n";
       f<<kvadrat.y1<<"\n";
       f<<kvadrat.x2<<"\n";
       f<<kvadrat.y2<<"\n";
       f<<kvadrat.light<<"\n";
         f.close();
}
int main()
{      setlocale(LC_ALL, "Russian");
       //Слова
       txCreateWindow(960,800);
       block kvadrat;

      save("file1.txt", kvadrat) ;

    return 0;
}
