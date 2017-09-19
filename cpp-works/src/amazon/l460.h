#include <iostream>
#include <unordered_map>
using namespace std;



class LFUCache {
private:

    struct Node {
        int key, value, fq;
        Node *prev, *next;
        Node(int key, int value, int fq) : key(key), value(value), fq(fq), prev(nullptr), next(nullptr) {
        }
        
    };

    struct FNode {
        int fq;
        FNode *prev, *next;
        Node *head, *tail;
        FNode(int fq) : fq(fq), prev(nullptr), next(nullptr) {
            head = new Node(0, 0, fq);
            tail = new Node(0, 0, fq);
            head->next = tail;
            tail->prev = head;
        }
    };

    int size, capacity;
    unordered_map<int, Node*> map; // key-value
    unordered_map<int, FNode*> fmap;
    FNode *fhead, *ftail;

    
    
public:
    LFUCache(int capacity) : size(0), capacity(capacity) {
        fhead = new FNode(0);
        ftail = new FNode(0);
        fhead->next = ftail;
        ftail->prev = fhead;
    }
    
    int get(int key) {
        if(map.find(key) == map.end()) return -1;
        Node *node = map[key];
        NodeAddFq(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        if(map.find(key) != map.end()) {
            Node *node = map[key];
            node->value = value;
            NodeAddFq(node);
            return;
        }
        if(size == capacity) {
            FNode *fnode = fhead->next;
            Node *node = fnode->head->next;
            RemoveNode(node);
            map.erase(node->key);
            delete node;
            if(fnode->head->next == fnode->tail) {
                RemoveFNode(fnode);
            }
            size--;
        }
        
        Node *node = new Node(key, value, 1);
        map[key] = node;
        InsertNode(node, fhead);
        size++;

    }
    
    void NodeAddFq(Node *node) {
        FNode *fnode = fmap[node->fq];
        RemoveNode(node);
        node->fq++;
        InsertNode(node, fnode);
        if(fnode->head->next == fnode->tail) {
            RemoveFNode(fnode);

        }
    }
    
    void RemoveNode(Node *node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    
    void RemoveFNode(FNode *fnode) {
        fnode->next->prev = fnode->prev;
        fnode->prev->next = fnode->next;
        fmap.erase(fnode->fq);
        delete fnode;
    }
    
    void InsertNode(Node *node, FNode *fprev) {
        FNode *fnode;
        if(fmap.find(node->fq) == fmap.end()) {
            fnode = new FNode(node->fq);
            fmap[node->fq] = fnode;
            InsertTail(node, fnode->tail);
            fnode->prev = fprev;
            fnode->next = fprev->next;
            fprev->next = fnode;
            fnode->next->prev = fnode;
        }
        else {
            fnode = fmap[node->fq];
            InsertTail(node, fnode->tail);
        }
    }
    
    void InsertTail(Node *node, Node *tail) {
        node->next = tail;
        node->prev = tail->prev;
        node->prev->next = node;
        tail->prev = node;
    }
};
