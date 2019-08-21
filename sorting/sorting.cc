#include <vector>
#include <iostream>
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


int main(){
    vector<int> a{6,5,3,4,2,0,1};
    vector<double> b{6.5,5.1,3.8,4.9,2.9,0.1,1.5,1.6,1.2,3.2};
    vector<int> c{25,1,2,-6,3,7,8,1,0,55,1,2,38,152};
    vector<int> temp;
    vector<double> temp2;
    heapSort(a);
    heapSort(b);
    // mergeSort(a,0,a.size()-1,temp);
    // mergeSort(b,0,b.size()-1,temp2);
    heapSort(c);
    print(a);
    print(b);
    print(c);
}