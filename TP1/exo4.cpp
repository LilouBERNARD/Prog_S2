#include "tp1.h"
#include <QApplication>
#include <iostream>
#include <time.h>
using namespace std; 

#define return_and_display(result) return _.store(result);


void allEvens(Array& evens, Array& array, int evenSize, int arraySize)
{
    Context _("allEvens", evenSize, arraySize); // do not care about this, it allow the display of call stack

    if (arraySize==0)
    {
        cout << "Toutes les valeurs du tableau ont été traitées";
        return;
    }
    if (array[arraySize]%2==0)
    {
        evens[evenSize]=array[arraySize];
        allEvens(evens, array, ++evenSize, --arraySize);
    }
    else
    {
        allEvens(evens, array, evenSize, --arraySize);
    }


    return;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // create a window manager
    MainWindow::instruction_duration = 400;  // make a pause between instruction display
    MainWindow* w = new AllEvensWindow(allEvens); // create a window for this exercice
    w->show(); // show exercice

    return a.exec(); // main loop while window is opened
}




