#ifndef TREE_H_
#define TREE_H_

#include<vector>
#include<iostream>

using namespace std;

// A tree is a connected, acylic undirected graph 
template<typename K = int>
class Tree{
    K root;
    vector<Tree*<K>> children;
    size_t num_children;
    public:
        Tree(vector<K> elements, size_t size): children{size} {
            root = Node<K>(elements[0]);
            for(int i=0; )
        }
        ~Tree(){
            delete root;
        }
};

#endif