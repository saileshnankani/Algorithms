#include "BST.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    BST<> bst;
    try{
        bst.search(5);
    }
    catch(const char* msg){
        cerr<<msg<<endl;
    }
    bst.insert(make_pair<int,int>(1,2));
    bst.insert(make_pair<int,int>(2,3));
    // bst.insert(make_pair<int,int>(4,5));
    // bst.insert(make_pair<int,int>(5,6));
    // bst.insert(make_pair<int,int>(6,7));
    // bst.insert(make_pair<int,int>(7,8));
    // bst.insert(make_pair<int,int>(8,9));
    // bst.insert(make_pair<int,int>(9,10));
    // bst.insert(make_pair<int,int>(10,11));
    // bst.insert(make_pair<int,int>(11,12));
    cout<<bst.search(1)<<endl;
    // cout<<bst.search(2)<<endl;
    // cout<<bst.search(3)<<endl;
    // cout<<bst.search(4)<<endl;
    // cout<<bst.search(5)<<endl;
    // cout<<bst<<endl;
}

