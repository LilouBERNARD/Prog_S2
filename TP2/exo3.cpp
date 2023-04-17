#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w=nullptr;


void bubbleSort(Array& toSort)
{
	for(int i=0; i<toSort.size()-1; i++)
	{
		for(int j=0; j<toSort.size()-i-1; j++)
		{
			if(toSort[j]>=toSort[j+1])
			{
				int tmp = toSort[j+1];
				toSort[j+1]=toSort[j];
				toSort[j]=tmp; 
			}
		}
	}
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount=20;
	MainWindow::instruction_duration = 100;
	w = new TestMainWindow(bubbleSort);
	w->show();

	return a.exec();
}
