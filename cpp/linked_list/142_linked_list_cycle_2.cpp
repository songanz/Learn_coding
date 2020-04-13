#include "../header.h"
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // 人家写的。。。好像还听有名：Floyd’s Cycle-Finding Algorithm
    // time 96%, memory 100%
    ListNode* detectCycle2(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        do {
            slow = slow->next;
            fast = fast->next->next;
        } while (fast != slow && fast != NULL && fast->next != NULL);

        if (fast == NULL || fast->next == NULL)
            return NULL;

        slow = head;  // 此时重置slow，利用步差。。。自己画个图看看
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
    // 我写的。。。很慢啊, 5.55%, memory 100%
    ListNode *detectCycle(ListNode *head) {
        if (!hasCycle(head)) return nullptr;
        ListNode* cursor = head;
        
        while (true){
            ListNode* slow = cursor;
            ListNode* fast = cursor->next;
            while (fast) {
                if (slow->next == cursor) return cursor;
                if (fast == slow) break;
                fast = fast->next->next;
                slow = slow->next;
            }
            cursor = cursor->next;
        }
    }
private:
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
    
    cout << s.detectCycle2(&l1) << '\n';

    ListNode ll1(1);
    ListNode ll2(2);

    ll1.next = &ll2;
    ll2.next = &ll1;

    cout << s.detectCycle2(&ll1)->val << '\n';
}