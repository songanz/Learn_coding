#include "header.h"
using namespace std;

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    // this is also a constructor
    MyLinkedList() {
        size_ = 0;
        t = nullptr;
        h = nullptr;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= size_ || index < 0) return -1;
        t = h;  // temp pointer
        int i = 0;
        while (i<index) {
            t = t->next;
            i++;
        }
        int ans = t->val;
        t = nullptr;
        return ans;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        t = new Node(val);
        t->next = h;
        h = t;
        t = nullptr;
        size_ += 1;
        return;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        t = new Node(val);
        if (size_ == 0) {
            h = t;
            t = nullptr;
            return;
        }
        Node *p = h;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = t;
        p = nullptr;
        t = nullptr;
        size_ += 1;
        return;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        if (index > size_) return;
        if (index == size_) {
            addAtTail(val);
            return;
        }
        t = h;
        int i = 1;
        while (i < index) {
            i++;
            t = t->next;
        }
        Node *p = new Node(val);
        p->next = t->next;        
        t->next = p;
        t = nullptr;
        p = nullptr;
        size_ += 1;
        return;        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size_) return;
        if (index == 0) {
            t = h;
            h = h->next;
            delete(t);
            t = nullptr;
            size_ -= 1;
            return;
        }
        int i = 1;
        t = h;
        while (i < index) {
            i++;
            t = t->next;
        }
        Node* p = t;
        t = t->next;
        p->next = t->next;
        delete(t);
        p = nullptr;
        t = nullptr;
        size_ -= 1;
        return;
    }
private:
    struct Node {
        int val;
        Node* next;
        Node(int v, Node* n = nullptr): val(v), next(n) {}  // constructor
    };
    Node* h;  // head
    int size_;
    Node* t; // temp node
};

int main() {
    MyLinkedList s;
    s.addAtHead(1);
    // s.addAtTail(3);
    // s.addAtIndex(1,9);
    // s.addAtIndex(1,5);
    s.addAtTail(3);
    // s.addAtHead(1);
    s.addAtIndex(1,2);
    // s.addAtIndex(5,2);
    // s.addAtIndex(3,0);
    // s.addAtTail(1);
    // s.addAtTail(0);
    // s.deleteAtIndex(6);
    s.get(-1);
    s.deleteAtIndex(1);
    s.get(-3);
    // s.addAtIndex(1,2);
    // s.get(0);
    // s.get(1);
    // s.addAtIndex(0,1);
    // s.get(0);
    // s.get(1);
}