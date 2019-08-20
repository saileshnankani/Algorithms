#ifndef HEAP_H_
#define HEAP_H_

#include "utility"
#include <vector>
#include <iostream>

// A heap implementation of a PriorityQueue with the
// largest key having highest priority (maxHeap)
// Takes in a vector of elements and supports insert, 
// deleteMax, and getMax operations 
template<typename K = int, typename V = int>
class Heap{

    std::vector<std::pair<K,V>> elements;

    // returns the size of the heap
    std::size_t getSize(){
        return elements.size();
    }

    // returns if index is last or not
    bool last(std::size_t index, size_t size){
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
    void fix_down(std::size_t index, size_t size){
        while(2*index+1<= size - 1){
            std::size_t lastChild = 2*index+1;
            if(!last(lastChild, getSize()) && elements[lastChild+1].first > elements[lastChild].first){
                lastChild+=1;
            }
            if(elements[index].first >= elements[lastChild].first){
                break;
            }
            std::swap(elements[lastChild].first , elements[index].first);
            index = lastChild;
        }
    }  

    // fix_down for just keys
    void fix_down(std::vector<K> &elements, std::size_t index, size_t size){
        while(2*index+1 <= size - 1){
            std::size_t lastChild = 2*index+1;
            if(!last(lastChild, size) && elements[lastChild+1] > elements[lastChild]){
                lastChild+=1;
            }
            if(elements[index] >= elements[lastChild]){
                break;
            }
            std::swap(elements[lastChild] , elements[index]);
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
            fix_down(0, getSize());
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

        // heap sorting using fix-down for only integers 
        // Time Complexity: O(n log n)
        void sort(std::vector<K>& inputElements){
            size_t n = inputElements.size();
            while(n>1){
                // delete the maximum
                std::swap(inputElements[0],inputElements[n-1]);
                n--;
                fix_down(inputElements, 0,n);
            }
        }

        // takes in a arbitrary vector of keys and heapifies it
        // Time Complexity: O(n)
        Heap(std::vector<std::pair<K,V>> input) : elements{input}{
            std::size_t size = getSize();
            std::size_t last = getSize()-1;
            std::size_t lastParent = (last-1)/2;
            if(size>0 && last>0){
                for(std::size_t i = lastParent+1; i-- > 0;){
                    fix_down(i,size);
                }
            }
        }

        // Constructor overloaded to accept no elements.
        // Useful for sorting
        Heap(std::vector<K> &inputElements){
            std::size_t size = inputElements.size();
            std::size_t last = size-1;
            std::size_t lastParent = (last-1)/2;
            if(size>0 && last>0){
                for (size_t i = lastParent+1; i-- > 0; ) {
                    fix_down(inputElements, i,size);
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