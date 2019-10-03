#include "header.h"
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

// DFS
// 注意这个是双向列表
// 不仅要连next，还要连prev
class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) return head;
        Node* t = head;
        Node* tn = nullptr;
        Node* tc = nullptr;
        while (t->next != nullptr || t->child != nullptr) {
            if(t->next != nullptr && t->child != nullptr) {
                tn = t->next;
                tc = t->child;
                tn->prev = nullptr;
                t->next = tc;
                t->child = nullptr;
                tc->prev = t;
                break;
            }
            else if (t->next != nullptr && t->child == nullptr) 
                t = t->next;
            else {
                t->next = t->child;
                t->child->prev = t;
                t->child = nullptr;
                t = t->next;
            }
        }
        if (tn == nullptr || tc == nullptr) return head;
        tn = flatten(tn);
        tc = flatten(tc);
        while(tc->next != nullptr) tc = tc->next;
        tc->next = tn;
        tn->prev= tc;
        return head;
    }
};

int main() {
    cout << "hello world" << '\n';
}