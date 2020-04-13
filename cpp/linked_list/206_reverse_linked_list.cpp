#include "../header.h"
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // time 99.88%, memory 100%
    ListNode* reverseList2(ListNode* head) {
        if (head == nullptr) return head;
        stack<int> st;
        ListNode* tail = head;
        while (tail) {
            st.push(tail->val);
            tail = tail->next;
        }
        ListNode* header = new ListNode(0);
        ListNode* cursor = header;
        while (!st.empty()) {
            ListNode* temp = new ListNode(st.top());
            cursor->next = temp;
            cursor = temp;
            st.pop();
        }
        return header->next;
    }
    // 用recursion的方式直接处理list，没有将list存出来，但是会很慢，memory 100%
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        pair<ListNode*, ListNode*> ans = reverseSub(head, tail);
        return ans.first;
    }
private:
    pair<ListNode*, ListNode*> reverseSub(ListNode* head, ListNode* tail) {
        if (head == nullptr || head->next == nullptr || head == tail) return  make_pair(tail, head);
        if (head->next == tail) {
            tail->next = head;
            head->next = nullptr;
            return make_pair(tail, head);
        }
        ListNode* cursor = head;
        while (cursor->next) {
            if (cursor->next == tail) break;
            cursor = cursor->next;
        }
        cursor->next = nullptr;
        pair<ListNode*, ListNode*> sub = reverseSub(head->next, cursor);  // 递归，两边往中间
        tail->next = sub.first;
        sub.second->next = head;
        head->next = nullptr;
        return make_pair(tail, head);
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

    ListNode* ans = s.reverseList(&l1);
    while (ans){
        cout << ans->val << ',';
        ans = ans->next;
    }
    cout << "\n";

    ListNode l5(1);
    ListNode l6(2);
    ListNode l7(3);
    ListNode l8(4);

    l5.next = &l6;
    l6.next = &l7;
    l7.next = &l8;

    ListNode* ans2 = s.reverseList2(&l5);
    while (ans2){
        cout << ans2->val << ',';
        ans2 = ans2->next;
    }
    cout << "\n";
}