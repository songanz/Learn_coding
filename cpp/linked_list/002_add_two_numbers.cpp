#include "../header.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int val = 0;
        int res = 0;
        ListNode* header = new ListNode(0);
        ListNode* cursor = header;
        
        while (l1 or l2) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            if (n1+n2+res >= 10) {
                val = n1+n2+res-10;
                res = 1;
            }
            else {
                val = n1+n2+res;
                res = 0;
            }
            
            cursor->next = new ListNode(val);
            cursor = cursor->next;
            
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        
        if (res != 0) {
            cursor->next = new ListNode(res);
            cursor = cursor->next;
        }
        
        return header->next;
    }
};

int main() {
    Solution s;
    vector<ListNode*> lists;
    ListNode l1(1);
    ListNode l2(1);
    ListNode l3(2);
    
    ListNode temp(4);
    l1.next = &temp;
    ListNode temp2(5);
    temp.next = &temp2;

    ListNode temp3(3);
    l2.next = &temp3;
    ListNode temp4(4);
    temp.next = &temp4;

    ListNode temp5(6);
    l3.next = &temp5;

    lists.push_back(&l1);
    lists.push_back(&l2);
    lists.push_back(&l3);

    ListNode* ans = s.addTwoNumbers(lists[0], lists[1]);
    while (ans){
        cout << ans->val << ',';
        ans = ans->next;
    }
    cout << "\n";
}