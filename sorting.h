#ifndef SORTING_H_
#define SORTING_H_
#include <iostream>

// Helper function for mergeSort
template<typename T>
void merge(T& A, int begin, int m, int end, T& temp);


// Merge sort algorithm. Takes O(N LOG N) time.
// T must have size() and iterators function defined
template<typename T>
void mergeSort(T& A,  int begin, int end, T& temp);


#endif