#include "header.h"
using namespace std;

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        
    }
private:
    struct Node {
        int val;
        Node* next;
        Node(int v, Node* n = nullptr): val(v), next(n) {}  // constructor
    };
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