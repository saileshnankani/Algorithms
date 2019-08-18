#include "heap.h"
#include <iostream>
#include <utility>
#include <string>

using namespace std;

int main(){
    vector<pair<int,int>> elements{make_pair<int,int>(10,5), make_pair<int,int>(80,8), 
        make_pair<int,int>(50,8), make_pair<int,int>(30,8), make_pair<int,int>(20,8), 
        make_pair<int,int>(60,8), make_pair<int,int>(10,8), make_pair<int,int>(40,8), 
        make_pair<int,int>(70,8)
    };
    Heap<int,int> heap(elements);
    cout<<heap.getMax().first<<endl;
    cout<<heap<<endl;
    heap.insert(100,-9);
    heap.insert(120,-9);
    cout<<heap.deleteMax().first<<endl;
    cout<<heap<<endl;
}