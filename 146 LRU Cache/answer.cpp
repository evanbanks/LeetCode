#include<unordered_map>

struct DLLNode {
    int key;
    int value;
    DLLNode* prev;
    DLLNode* next;
    
    DLLNode(int key, int val, DLLNode* p, DLLNode* n)
        : key {key}, value {val}, prev {p}, next {n}
    {}
};


void DeleteHelper(DLLNode* c){
    if(!c) return;
    DeleteHelper(c->next);
    delete c;
}


class LRUCache {
private:
    std::unordered_map<int,DLLNode*> cache;
    DLLNode* head;
    DLLNode* tail;
    int max_size;

    
    void UpdatePriority(DLLNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->prev = head;
        node->next = head->next;
        head->next = head->next->prev = node;
    }
    
    
public:
    LRUCache(const int capacity)
        : max_size {capacity}
    {
        head = new DLLNode(0,0,nullptr,nullptr);
        head->next = tail = new DLLNode(0,0,head,nullptr);
        cache.reserve(capacity+1);
    }
    
    
    ~LRUCache() {
        DeleteHelper(head);
    }
    
    
    int get(const int key) {
        if(cache.find(key) != cache.end()){
            auto node = cache[key];
            UpdatePriority(node);
            return node->value;
        }
        return -1;
    }
    
    
    void put(const int key, const int value) {
        if (cache.find(key) != cache.end()){
            cache[key]->value = value;
            UpdatePriority(cache[key]);
        } else {
            auto new_node = new DLLNode(key, value, head, head->next);
            head->next = head->next->prev = new_node;
            cache.emplace(key, new_node);
            if (cache.size() > max_size){
                DLLNode* node = tail->prev;
                node->prev->next = tail;
                tail->prev = node->prev;
                cache.erase(node->key);
                delete node;
            }
        }
    }
};