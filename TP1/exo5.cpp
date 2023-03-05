#include "tp1.h"
#include <QApplication>
#include <time.h>

int isMandelbrot(Point z, int n, Point point)
{
    if (n==0)
    {
        return 0;
    }

    if (sqrt(z.x*z.x+z.y*z.y)>2) //module de Z > 2 
    {
       return n;
    }

    else
    {
        
        z.x=(z.x*z.x-z.y*z.y)+point.x;
        z.y=(2*z.x*z.y)+point.y;
        return isMandelbrot(z,n-1,point);
    }

    // recursiv Mandelbrot

    // check n

    // check length of z
    // if Mandelbrot, return 1 or n (check the difference)
    // otherwise, process the square of z and recall
    // isMandebrot
    return 0;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = new MandelbrotWindow(isMandelbrot);
    w->show();

    a.exec();
}


