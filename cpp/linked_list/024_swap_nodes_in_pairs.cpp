#include "../header.h"
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}  // constructor
private:
    friend class Solution;
};

// time 100%, memory 100%
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* cursor = head;
        head = head->next;
        
        ListNode* nextN = cursor->next;
        ListNode* nnextN = nextN->next;

        nextN->next = cursor;
        cursor->next = swapPairs(nnextN);  // tail recursion

        return head;
    }
};

int main() {
    Solution s;
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);

    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;

    ListNode* ans = s.swapPairs(&l1);
    while (ans){
        cout << ans->val << ',';
        ans = ans->next;
    }
    cout << "\n";

}