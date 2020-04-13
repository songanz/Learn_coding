#include "../header.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;  // 一个指针存下个ListNode
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 1) return lists[0];
        ListNode dummy(0);
        ListNode *tail = &dummy;  // 对指针进行操作而不是对对象进行操作
        vector<int> q;
        int n = lists.size();
        
        for (int i = 0; i < n; i++) {
            ListNode *l = lists[i];
            while (l) {
                int v = l->val;  // 对指向struct的指针，取地址里面的值，用->
                if (l) q.push_back(v);
                l = l->next;
            }        
        }
        sort(q.begin(),q.end());  // nlog_2(n)
        int m = q.size();
        for (int i = 0; i < m; i++) {
            // new： 为变量请求新内存， 返回地址
            ListNode *temp = new ListNode(q[i]);
            tail->next = temp;
            tail = tail->next;  // 对指向struct的指针，取地址里面的值，用->
        }
        return dummy.next;
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

    cout << s.mergeKLists(lists)->val << endl;
}