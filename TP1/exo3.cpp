#include "tp1.h"
#include <QApplication>
#include <time.h>
#include <iostream>
using namespace std; 

#define return_and_display(result) return _.store(result);


int search(int value, Array& toSort, int taille)
{
    Context _("search", value, taille); // do not care about this, it allow the display of call stack
    
    if(size>0)
    {
        if(value==toSort[size-1])
        {
            return_and_display(size-1);
        } 
        else 
        {
            return_and_display(search(value, toSort, size-1));
        }
    } 
    else 
    {
        return_and_display(-1);
    }
    return_and_display(-1);

    // your code
    // check the last cell and if it does not correspond
    // then consider a smaller array when recalling search
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // create a window manager
    MainWindow::instruction_duration = 400;  // make a pause between instruction display
    MainWindow* w = new SearchWindow(search); // create a window for this exercice
    w->show(); // show exercice

    return a.exec(); // main loop while window is opened
}



  
