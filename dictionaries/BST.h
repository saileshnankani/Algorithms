#ifndef __BST__
#define __BST__
#include "utility"
#include <iostream>

template<typename K, typename V>
class BST;

// An implementation of Node to be used in BST
template<typename K = int, typename V = int>
class Node{
    public:
        std::pair<K,V> element;
        BST<K,V>* left;
        BST<K,V>* right;
        // Constructor
        Node(std::pair<K,V> newPair) : left{nullptr}, right{nullptr} {
            element.first = newPair.first;
            element.second = newPair.second;
        }
        // Destructor
        ~Node(){
            delete left;
            delete right;
        }
};

// An implementation of BST using Node. Can also be done using 
// vectors. Supports insert, delete, and search.
template<typename K = int, typename V = int>
class BST{
    Node<K,V>* root;    
    public:
        BST() : root{nullptr} {};
        ~BST(){
            delete root;
        };

        V search(K key){
            if(root){
                if(root->element.first==key){
                    return root->element.second;
                }
                else if(root->element.first > key){
                    return root->left->search(key);
                }
                else{
                    return root->right->search(key);
                }
            }
            else{
                throw "Key not found.";
            }
        }

        void insert(std::pair<K,V> newElement){
            if(root){
                if(root->element.first > newElement.first){
                    root->left->insert(newElement);
                }
                else{
                    root->right->insert(newElement);
                }
            }
            else{
                root = new Node<K,V>(std::make_pair<K&,V&>(newElement.first,newElement.second));
                return;
            }
        }

<<<<<<< HEAD
<<<<<<< HEAD
=======
        friend std::ostream& operator<<(std::ostream& out, const BST& other){
            if(other.root){
                std::cout<<other.root->left<<std::endl;
=======
        friend std::ostream& operator<<(std::ostream& out, const BST& other){
            if(other.root){
                std::cout<<"YAY"<<std::endl;
                std::cout<<other.root->left<<std::endl;
                std::cout<<"HEY"<<std::endl;
>>>>>>> c327ed9... WIP: Dictionaries and DP
                out<<other.root->left<<"("+ std::to_string(other.root->element.first)+","+ std::to_string(other.root->element.second)+") "<<other.root->right;
            }
            else{
                out<<"";
            }
        }
};
<<<<<<< HEAD
>>>>>>> 154c0ba... Cleaned up
=======
>>>>>>> c327ed9... WIP: Dictionaries and DP

#endif