#include "heap.h"
#include <iostream>
#include <utility>
#include <string>
#include <vector>

using namespace std;

template<typename T>
T findKthLargest(std::vector<T> elements, size_t k){
    Heap<T> heap(elements);
    T max = 0;
    for(int j=0; j<=k; j++){
        max = heap.deleteMaxKeys();
    }
    return max;
}

int main(){
    vector<pair<int,int>> elements{make_pair<int,int>(10,5), make_pair<int,int>(80,8), 
        make_pair<int,int>(50,8), make_pair<int,int>(30,8), make_pair<int,int>(20,8), 
        make_pair<int,int>(60,8), make_pair<int,int>(10,8), make_pair<int,int>(40,8), 
        make_pair<int,int>(70,8)
    };
    Heap<> heap(elements);
    cout<<heap<<endl;
    cout<<heap.getMax().first<<endl;
    cout<<heap<<endl;
    heap.insert(100,-9);
    heap.insert(120,-9);
    cout<<heap.deleteMax().first<<endl;
    cout<<heap<<endl;

    vector<int> elements2{1,2,3,4,5,6,7,8,9};

    for(int i=0; i<elements2.size(); i++){
        cout<<findKthLargest(elements2 , i)<<endl;
    }
}