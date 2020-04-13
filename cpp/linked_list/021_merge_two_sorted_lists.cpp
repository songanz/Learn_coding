#include "../header.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;  // 一个指针存下个ListNode
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode header(0);
        ListNode* hh = &header;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                hh->next = l1;
                l1 = l1->next;
            }
            else {
                hh->next = l2;
                l2 = l2->next;
            }
            hh = hh->next;
        }

        if (l1) hh->next = l1;
        if (l2) hh->next = l2;
        return header.next;
    }

    ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
        // If one of the list is emptry, return the other one.
        if(!l1 || !l2) return l1 ? l1 : l2;
        // The smaller one becomes the head.
        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
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

    ListNode ll1(1);
    ListNode ll2(2);

    ll1.next = &ll2;
    
    // cout << s.mergeTwoLists(&l1, &ll1) << '\n';

    cout << s.mergeTwoLists2(&ll1, &l1) << '\n';
}