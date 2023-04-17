#include <QApplication>
#include <time.h>
#include <iostream>
#include "tp2.h"
using namespace std; 

MainWindow* w = nullptr;



void selectionSort(Array& toSort)
{
    int tmp, min; 
    for(int i=0; i<toSort.size(); i++)
    {
        min = i; 
        tmp = toSort[i];

        for(int j = i ; j < toSort.size() ; j++)
        {
            if(toSort[j] < toSort[i])
            {
                min = j;
            }
            
        }
        toSort[i]=toSort[min];
        toSort[min]=tmp; 
        
    }
}




int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    uint elementCount=15; // number of elements to sort
    MainWindow::instruction_duration = 100; // delay between each array access (set, get, insert, ...)
    w = new TestMainWindow(selectionSort); // window which display the behavior of the sort algorithm
    w->show();

	return a.exec();
}
