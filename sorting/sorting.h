#ifndef SORTING_H_
#define SORTING_H_
#include <vector>
#include <utility>

// Helper function for mergeSort
template<typename T>
void merge(T& A, int begin, int m, int end, T& temp);

// Merge sort algorithm. 
// T must have size() and iterators function defined
template<typename T>
void mergeSort(T& A, int begin, int end, T& temp);

// Heap sort algorithm. Sorts by the key K.  
// Time Complexity: O(n log n)
// Space Complexity: O(1)
template<typename K>
void heapSort();

#endif