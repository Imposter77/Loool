#include "TXLib.h"

int main()
{
    txCreateWindow (1280, 720);
    txSetFillColour(TX_RED);

    HDC knopkazagolovok=txLoadImage("êíîïêà çàãîëîâêè.bmp");
    HDC knopkatext=txLoadImage("êíîïêà òåêñò.bmp");
    HDC knopkakartinki=txLoadImage("êíîïêà êàðòèíêè.bmp");

    //txTransparentBlt(txDC(), 100, 100, 400, 250, knopkazagolovok, 0, 0, TX_WHITE);

    //txTransparentBlt(txDC(), 400, 100, 400, 250, knopkakartinki, 0, 0, TX_WHITE);

    int x=100;
    int y=200;
    const char* name="";
    while (1)
    { txClear();
        txBegin();
        txTransparentBlt(txDC(), 800, 0, 400, 250, knopkatext, 0, 0, TX_WHITE);
        if (txMouseButtons()==1&&txMouseX()>800&&txMouseX()<1200&&txMouseY()>0&&txMouseY()<250)
        { cout<<txMouseX()<<" "<<txMouseY()<<std::endl;
            name = txInputBox ("ÂÂÅÄÈÒÅ ÒÅÊÑÒ", "ÄÈÀËÎÃÎÂÎÅ ÎÊÍÎ", "ÂÀØ ÒÅÊÑÒ");
            txTextOut(x, y, name);
           // y=y+30;
            txSleep(120);


        }
         if (txMouseButtons()==1&&txMouseX()>x&&txMouseX()<x+100&&txMouseY()>y-10&&txMouseY()<y+20)
            {
                cout<<"";
                 while (txMouseButtons()==1)
            {


                x=txMouseX();
                y=txMouseY();}
            }
            txTextOut(x, y, name);
            txEnd();
    }

    return 0;
    }
