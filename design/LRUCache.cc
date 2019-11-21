#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class LRUCache {
    
    class DLinkedNode{
        public: 
            int key;
            int value;
            DLinkedNode* pre;
            DLinkedNode* post;

            DLinkedNode(int key = 0, int value = 0) : key{key}, value{value} {
                pre = nullptr;
                post = nullptr;
            }
    };
    
    void addNode(DLinkedNode* node){
        node->post = head->post;
        node->pre = head;
        
        head->post->pre = node;
        head->post = node;
        
    }
    
    void removeNode(DLinkedNode* node){
        DLinkedNode* node_pre = node->pre;
        DLinkedNode* node_post = node->post;
        node_pre->post = node_post;
        node_post->pre = node_pre;
    }
    
    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addNode(node);
    }
    
    DLinkedNode* removeTail(){
        DLinkedNode* tail_node = tail->pre;
        removeNode(tail_node);
        return tail_node;
    }
    
    int capacity;
    int count;
    DLinkedNode* head;
    DLinkedNode* tail;
    
    
public:
    unordered_map<int,DLinkedNode*> cache;
    LRUCache(int capacity) : capacity{capacity}, count{0} {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->pre = nullptr;
        tail->post = nullptr;
        head->post = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end()){
            return -1;
        }
        else{
            DLinkedNode* node = cache[key];
            moveToHead(node);
            return node->value;
        }
    }
    
    void put(int key, int value) {
        DLinkedNode* node;
        if(cache.find(key)!=cache.end()){
            node = cache[key];
            moveToHead(node);
            node->value = value;
        }
        else{
            node = new DLinkedNode();
            node->key = key;
            node->value = value;
            addNode(node);
            cache[key] = node;
            count++;
            if(count>capacity){
                count--;
                DLinkedNode* temp = removeTail();
                cache.erase(temp->key);
            }
        }
      }
};

int main(){
     LRUCache* newCache = new LRUCache(2);
     newCache->put(1,1);
     newCache->put(2,2);
     newCache->get(1);
     newCache->put(3,3);
     newCache->get(2);
     newCache->put(4,4);
     newCache->get(1);
     newCache->get(3);
     newCache->get(4);
     int size = newCache->cache.size();
     int counter = 0;
    for(auto it = newCache->cache.begin(); it!=newCache->cache.end(); it++){
        cout<<(*it).second->key<<":"<<(*it).second->value;
        if(counter!=size-1){
            cout<<"->";
        }
        counter++;
    }
    cout<<endl;
}