#include "tp4.h"
#include "mainwindow.h"

#include <QApplication>
#include <time.h>
#include <stdio.h>

MainWindow* w = nullptr;
using std::size_t;
using std::string;

int Heap::leftChild(int nodeIndex)
{
    return nodeIndex*2+1;
}

int Heap::rightChild(int nodeIndex)
{
    return nodeIndex*2+2;
}

void Heap::insertHeapNode(int heapSize, int value)
{
	// use (*this)[i] or this->get(i) to get a value at index i
	int i = heapSize;
	this->get(i) = value;

	while(i>0 && this->get(i) > this->get((i-1)/2))
	{
		swap(i, (i-1)/2); 
		i = (i-1)/2; 
	}
}

void Heap::heapify(int heapSize, int nodeIndex)
{
	// use (*this)[i] or this->get(i) to get a value at index i
	int fg = this->leftChild(nodeIndex); 
	int fd = this->rightChild(nodeIndex); 
	int i_max = nodeIndex;
	
	
		if(fg<heapSize)
		{
			if(this->get(fg) > this->get(i_max))
			{
				i_max = fg; 
			}
		}
		if(fd<heapSize)
		{
			if(this->get(fd)> this->get(i_max))
			{
				i_max = fd; 
			}
		}
		if(nodeIndex != i_max)
		{
			swap(nodeIndex, i_max); 
			this->heapify(heapSize, i_max); 
		}
}

void Heap::buildHeap(Array& numbers)
{
	int i; 
	for(i=0; i<number.size(; i++))
	{
		this->insertHeapNode(i, numbers.get(i)); 
	}

}

void Heap::heapSort()
{
	int i; 

	for(i=this->size()-1, i>=0, i++)
	{
		swap(0,i); 
		heapify(i, 0); 
	}

}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    MainWindow::instruction_duration = 50;
    w = new HeapWindow();
	w->show();

	return a.exec();
}
