#include "../header.h"
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // time 95%, memory 100%
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast) {
            if (fast->next == nullptr) return false;
            if (fast == slow) return true;
            fast = fast->next->next;
            slow = slow->next;
        }
        // fast is nullptr --> no circle
        return false;
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
    
    cout << s.hasCycle(&l1) << '\n';

    ListNode ll1(1);
    ListNode ll2(2);

    ll1.next = &ll2;
    ll2.next = &ll1;

    cout << s.hasCycle(&ll1) << '\n';
}