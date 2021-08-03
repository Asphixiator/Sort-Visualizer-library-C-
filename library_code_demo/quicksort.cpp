// //Quick sort program code
#include "SortVisualizer.h"
#include<iostream>

using namespace std;

int partition(vector<int>* a, int low, int high) {
    int lowIndex = low - 1;
    int pivot = a->at(high);

    for(int i = low; i < high; ++i)
    {
        if(a->at(i) <= pivot)
        {
            ++lowIndex;
            swap(lowIndex, i);
        }
    }

    ++lowIndex;
    swap(lowIndex, high);

    return lowIndex;
}

void quickSort(vector<int>* a, int low, int size) {
    int high = size;
    if (low < high) {
        int j = partition(a, low, high);
        quickSort(a, low, j-1);
        quickSort(a, j+1, high);
    }
}

void visualizeSort(vector<int>* a, int length) {
    quickSort(a, 0, length-1);
}

int main(int argc, char* argv[]) {
    setupVisualizer(argc, argv, visualizeSort);

    return 0;
}