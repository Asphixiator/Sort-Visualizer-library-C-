// Bubble sort program code
#include "SortVisualizer.h"
#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>    

using namespace std;

void bubbleSort(vector<int>* a, int size)
{
	bool swapped;

	for(int i = 0; i < size - 1; ++i)
	{
		swapped = false;	

		for(int j = 0; j < size - i - 1; ++j)
		{
			if(a->at(j) > a->at(j+1))
			{
				swapped = true;
				swap(j, j+1);
			}
		}

		if(swapped == false)
		{
			break;
		}
	}
}

void visualizeSort(vector<int>* a, int length) {
    bubbleSort(a, length-1);
}

int main(int argc, char* argv[]) {
    setupVisualizer(argc, argv, visualizeSort);

    return 0;
}