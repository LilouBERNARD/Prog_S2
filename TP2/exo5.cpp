#include <QApplication>
#include <time.h>
#include "tp2.h"

MainWindow* w=nullptr;

void merge(Array& first, Array& second, Array& result);

void splitAndMerge(Array& origin)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)
	if(origin.size()<=1)
	{
		return; 
	}

	// initialisation
	Array& first = w->newArray(origin.size()/2);
	Array& second = w->newArray(origin.size()-first.size());
	
	// split
	for(int i=0; i<first.size(); i++)
	{
		first[i]=origin[i];
	}
	for(int j=0; j<second.size(); j++)
	{
		second[j]=origin[first.size()+j];
	}

	// recursiv splitAndMerge of lowerArray and greaterArray
	splitAndMerge(first);
	splitAndMerge(second);

	// merge
	merge(first,second,origin);
}

void merge(Array& first, Array& second, Array& result)
{
	int i1=0; 
	int i2=0; 

	while(i2!=first.size()|| i1!=second.size())
	{
		if(i2==first.size())
		{
			result[i1+i2]=second[i1];
			i1++; 
		}
		else if(i1==second.size())
		{
			result[i1+i2]=second[i2];
			i2++;
		}
		else if (first[i2]<second[i1])
		{
			result[i1+i2]=first[i2];
			i2++; 
		}
		else
		{
			result[i1+i2]=second[i1];
			i1++;
		}
		
	}

}

void mergeSort(Array& toSort)
{
    splitAndMerge(toSort);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(mergeSort);
	w->show();

	return a.exec();
}
