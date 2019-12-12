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
        list<int> n1;
        list<int> n2;
        ListNode* ans = new ListNode(0);
        ListNode* head = ans;
        
        while (l1) {
            n1.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            n2.push_back(l2->val);
            l2 = l2->next;            
        }
        
        list<int> num;
        int res = 0;
        while (n1.size() != 0 or n2.size() != 0) {
            int d1 = 0;
            if (n1.size() != 0) {
                d1 = n1.back();
                n1.pop_back();
            }
            
            int d2 = 0;
            if (n2.size() != 0) {
                d2 = n2.back();
                n2.pop_back();
            }        
            
            int a = d1 + d2 + res;
            if (a>=10) {
                num.push_front(a-10);
                res = 1;
            }
            else {
                num.push_front(a);
                res = 0;
            }
        }
        if (res != 0) num.push_front(res);
        
        while (num.size() != 0) {
            head->val = num.front();
            num.pop_front();
            if (num.size() != 0) {
                head->next = new ListNode(0);
                head = head->next;
            }
        }
        
        return ans;  
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