#ifndef SortVisualizer_H
#define SortVisualizer_H

#include <vector>

void setupVisualizer(int argc, char** argv, void (*sortAlgorithm) (std::vector<int>*, int));
void swap(int a, int b);

#endif