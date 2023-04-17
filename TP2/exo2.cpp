#include <QApplication>
#include <time.h>
#include <iostream>
#include "tp2.h"
using namespace std; 

MainWindow* w=NULL;


void insertionSort(Array& toSort)
{
	Array& sorted= w->newArray(toSort.size()); 
	sorted[0] = toSort[0]; 
	int i; 
	int j; 
	int index; 
	int tmp; 

	for(i=1; i< toSort.size(); i++)
	{
		index = -1; 
		j=0;
		while(j<i && sorted[j]<toSort[i])
		{
			j++;
		}
		index=j;
		if(index>= 0)
		{
			for(int position=i; position>index; position--)
			{
				sorted[position]=sorted[position-1];
			}
			sorted[index]=toSort[i];
		}
		else
		{
			sorted[i]=toSort[i];
		}
		
	}

	// insertion sort from toSort to sorted
	
	toSort=sorted; // update the original array
}



int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    uint elementCount=15; // number of elements to sort
    MainWindow::instruction_duration = 100; // delay between each array access (set, get, insert, ...)
    w = new TestMainWindow(insertionSort); // window which display the behavior of the sort algorithm
	w->show();

	return a.exec();
}
