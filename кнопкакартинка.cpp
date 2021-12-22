#include "TXLib.h"

int main()
{
    txCreateWindow (1280, 720);
    txSetFillColour(TX_RED);

    //HDC knopkazagolovok=txLoadImage("êíîïêà çàãîëîâêè.bmp");
    //HDC knopkatext=txLoadImage("êíîïêà òåêñò.bmp");
   HDC knopkakartinki=txLoadImage("êíîïêà êàðòèíêà.bmp");


    //txTransparentBlt(txDC(), 100, 100, 400, 250, knopkazagolovok, 0, 0, TX_WHITE);
    //txTransparentBlt(txDC(), 100, 100, 500, 319, kartinka, 0, 0, TX_WHITE);

    int xPic=100;
    int yPic=200;
    const char* name="";
    int visible=0;
    HDC kartinka;
    while (1)
    { txClear();
        txBegin();
        int x;
        int y;
        txTransparentBlt(txDC(), 800, 0, 400, 250, knopkakartinki, 0, 0, TX_WHITE);
        if (visible) txTransparentBlt(txDC(), xPic, yPic, 500, 319, kartinka, 0, 0, TX_WHITE);
        if (txMouseButtons()==1&&txMouseX()>800&&txMouseX()<1200&&txMouseY()>0&&txMouseY()<250)
        { cout<<txMouseX()<<" "<<txMouseY()<<std::endl;
            name = txInputBox ("ÂÂÅÄÈÒÅ ÊÀÐÒÈÍÊÓ", "ÄÈÀËÎÃÎÂÎÅ ÎÊÍÎ", "ÍÀÇÂÀÍÈÅ.bmp");
            kartinka=txLoadImage(name);
            visible=1;
             while (txMouseButtons()!=1)
            {
                ;
            }
             while (txMouseButtons()==1)
            {
                xPic=txMouseX();
                yPic=txMouseY();
            }

           // y=y+30;
            txSleep(320);


        }
         if (txMouseButtons()==1&&txMouseX()>x&&txMouseX()<x+100&&txMouseY()>y-10&&txMouseY()<y+20)
            {

                 while (txMouseButtons()==1)
            {


                x=txMouseX();
                y=txMouseY();}
            }
            txEnd();
    }

    return 0;
    }
