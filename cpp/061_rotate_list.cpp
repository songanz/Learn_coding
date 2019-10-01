#include "header.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k==0 || head == NULL || head->next == NULL) return head;
        int c = 1;
        ListNode* h = head;
        while (head->next != NULL) {
            c++;
            head = head->next;
        }
        k = k % c;
        if (k == 0) return h;
        head->next = h;
        int i = 1;
        while (i<(c-k)) {
            ++i;
            h = h->next;
        }
        ListNode *ans = h->next;
        h->next = NULL;
        return ans;            
        
    }
};

int main() {
    ListNode head(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    head.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    Solution s;
    cout << s.rotateRight(&head, 2)->val << endl;

}