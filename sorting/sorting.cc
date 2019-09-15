#include <vector>
#include <iostream>
#include <utility>
#include <cstdlib>
#include <array>
#include "sorting.h"
#include "../heap/heap.h"

using namespace std;

// Printing out the elements of a container
// Needs operator[], operator<<, and iterators defined
template<typename T>
void print(T container){
    for(auto x: container){
        cout<<x<<" ";
    }
    cout<<endl;
}

template<typename T>
void merge(T& A, int begin, int m, int end, T& temp){
    for(int i=begin; i<=end; i++){
        temp[i] = A[i];
    }
    int temp_begin = begin;
    int temp_end = m+1;  
    for(int k = begin; k<=end; k++){
        if(temp_begin > m){
            A[k] = temp[temp_end++];
        }
        else if(temp_end > end){
            A[k] = temp[temp_begin++];
        }
        else if(temp[temp_begin] <= A[temp_end]){
            A[k] = temp[temp_begin++];
        }
        else{
            A[k] = temp[temp_end++];
        }
    }
}



template<typename T>
void mergeSort(T& A,  int begin, int end, T& temp){
    if(temp.size()==0){
        for(int i=begin; i<=end; i++){
            temp.push_back(A[i]);   
        }
    }   
    if(end<=begin){
        return;
    }
    else{
        int m = (end+begin)/2;
        mergeSort(A,begin,m,temp);
        mergeSort(A,m+1,end,temp);
        merge(A,begin,m,end,temp);
    }
}

// heapifies the inputElements and heapSorts it
template<typename K>
void heapSort(std::vector<K>& inputElements){
    Heap<K> heap(inputElements);
    inputElements = heap.sort();
}

// partition function
// Rearranges the container A to A' and returns pivot-index i 
// so that pivot value A[p] is in the sorted position (i) in A' 
// and A'[b] < A'[p] for b < p and A'[c] > A'[p] for c > p 
template<typename K>
size_t partition(const K begin, const K end, size_t p){
    size_t size = end-begin;
    std::swap(*(begin+p),*(begin+size-1));
    auto val = *(begin+size-1);
    int i = -1;
    int j = size - 1;
    while(i<j){
        do
        {
            i++;
        } while (i<size && *(begin+i)<val);
        do{
            j--;
        }
        while(j>0 && *(begin+j) > val);
        if(i<j){
            std::swap(*(begin+i),*(begin+j));
        }
    }
    std::swap(*(begin+size-1),*(begin+i));
    return i;
}

template<typename K>
size_t choose_pivot(const K begin, const K end){
    return end-begin-1;
}

// for randomized quick-sort
// Time Complexity: still Theta(n log n)
template<typename K>
size_t choose_random_pivot(const K begin, const K end){
    return (size_t)(rand()%(end-begin));
}

// Quick sort
template<typename K>
void quicksort(const K begin, const K end){
    if(end-begin<=1) return;
    size_t p = choose_pivot(begin,end);
    size_t i = partition(begin, end,p);
    quicksort(begin, begin+i);
    quicksort(begin+i+1, end);
}

// Quickselect: To find the ith smallest element in an unordered list
// Average case time complexity: Theta(n)
// Worst case: Theta(n^2)
// Best case: Theta(n)
template<typename K>
int quickselect(const K begin, const K end, size_t i){
    size_t p = choose_random_pivot(begin, end);
    size_t m = partition(begin, end, p);
    if(m==i){
        return *(begin+m);
    }   
    else if(m>i){
        return quickselect(begin, begin+m, i);
    }
    else{
        return quickselect(begin+m+1,end,i-m-1);
    }
} 

int get_dth_digit(int number, int d){
    int digit = 0;
    while(d>0 && number>0){
        digit = number%10;
        number/=10;
        d--;
    }
    if(d>0){
        return 0;
    }
    return digit;
}

// CountSort
// d is the digit we wish to sort
// R is the base of the numbers to be sorted
// Time Complexity: Theta(n+R)
// Space Complexity: Theta(n+R)
template<typename K>
void key_based_index_count_sort(const K begin, const K end, int d, int R){
    // count how many of each kind are
    int size = end-begin;
    int count[R] = {0};
    for(int i=0; i<size; i++){
        count[get_dth_digit(*(begin+i),d)]++;
    }

    // find left boundary for each kind
    int idx[R] = {0};
    for(int i=1; i<size; i++){
        idx[i] = idx[i-1] + count[i-1];
    } 

    // move to a newly sorted order, then copy back
    int aux[size] = {0};
    for(int i=0; i<size; i++){
        aux[idx[get_dth_digit(*(begin+i),d)]] = *(begin+i);
        idx[get_dth_digit(*(begin+i),d)]++;
    }

    for(int i=0; i<size; i++){
        *(begin+i) = aux[i];
    }
}

// LSD-Radix-Sort (stable)
// Sorts starting from least significant digit
// m is the number of digits in the numbers
// R is the radix
// Time Complexity: Theta(m*(n+R))
// Space Complexity: Theta(n+R)
template<typename K>
void LSD_radix_sort(const K begin, const K end, int m, int R){
    for(int d=1; d<R; d++){
        key_based_index_count_sort(begin, end,d,R);
    }
}

int main(){
    vector<int> a{6,5,3,4,2,-8,1};
    vector<double> b{6.5,5.1,3.8,4.9,2.9,0.1,1.5,1.6,1.2,3.2};
    vector<int> c{1,0,1};
    vector<int> d{5,9,85,2,3,12,4,1,5,41,2,5};
    vector<int> e{25,1,2,-6,3,7,8,1,0,55,1,2,38,152};
    vector<int> f{6,5,3,4,2,-8,1};
    vector<int> g{123,230,21,320,210,232,101};
    vector<int> temp;
    vector<double> temp2;
    mergeSort(b,0,b.size()-1,temp2);
    heapSort(c);
    print(a);
    print(b);
    print(c);
    quicksort(a.begin(),a.end());
    print(a);
    quicksort(e.begin(),e.end());
    print(e);
    LSD_radix_sort(g.begin(),g.end(),3,4);
    print(g);
}