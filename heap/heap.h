#ifndef HEAP_H_
#define HEAP_H_

#include "utility"
#include <vector>
#include <iostream>

// A heap implementation of a PriorityQueue with the
// largest key having highest priority (maxHeap)
// Takes in a vector of elements and supports insert, 
// deleteMax, and getMax operations 
template<typename K, typename V>
class Heap{

    std::vector<std::pair<K,V>> elements;

    // returns the size of the heap
    std::size_t getSize(){
        return elements.size();
    }

    // returns if index is last or not
    bool last(std::size_t index){
        std::size_t size = getSize();
        if(index==size-1){
            return true;
        }
        else{
            return false;
        }
    }     


    // bubbles up starting from parent of K 
    // Time Complexity: O(log n)
    void fix_up(K index){ 
        K parentIndex = (index-1)/2; 
        while(parentIndex >= 0 && elements[parentIndex].first < elements[index].first){
            std::swap(elements[index],elements[parentIndex]);
            index = parentIndex;
            parentIndex = (index-1)/2;
        }
    }

    // bubbles down 
    // Time Complexity: O(n log n)
    void fix_down(std::size_t index){
        std::size_t size = getSize();
        while(2*index+1<= size - 1){
            std::size_t lastChild = 2*index+1;
            if(!last(lastChild) && elements[lastChild+1].first > elements[lastChild].first){
                lastChild+=1;
            }
            if(elements[index].first >= elements[lastChild].first){
                break;
            }
            std::swap(elements[lastChild].first , elements[index].first);
            index = lastChild;
        }
    }  


    public:

        // deletes the max element and returns it. 
        // Time Complexity: O(n log n)
        std::pair<K,V> deleteMax(){
            std::size_t last = getSize()-1;
            std::swap(elements[0],elements[last]);
            std::pair<K,V> max = elements[last];
            elements.pop_back();
            fix_down(0);
            return max;
        }

        // returns the max element. 
        // Time Complexity: O(1)
        std::pair<K,V> getMax(){
            return elements[0];
        }

        // uses fix_up.
        // Time Complexity: O(n log n)
        void insert(K key, V val){
            std::pair<K,V> newPair = std::make_pair(key,val);
            elements.push_back(newPair);
            std::size_t lastIndex = getSize()-1;
            fix_up(lastIndex);
        }

        // takes in a arbitrary vector of keys and heapifies it
        // Time Complexity: O(n)
        Heap(std::vector<std::pair<K,V>> input) : elements{input}{
            std::size_t last = getSize()-1;
            std::size_t lastParent = (last-1)/2;
            if(last>0){
                for(std::size_t i = lastParent; i>=0; i--){
                    fix_down(i);
                    if(i==0){
                        break;
                    }
                }
            }
        }

        ~Heap(){};

        friend std::ostream& operator<<(std::ostream& out, const Heap& other){
            for(int i = 0; i<other.elements.size(); i++){
                std::cout<<other.elements[i].first<<" ";
            }
            std::cout<<std::endl;
        }
};

#endif