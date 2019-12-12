#include "../header.h"
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s && t) return false;
        if (s && !t) return false;
        if (s->val != t->val) return isSubtree(s->left, t) || isSubtree(s->right, t);
        return (isSameTree(s->left, t->left) && isSameTree(s->right, t->right)) \
        || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
private:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p ^ !q) return false;
        if (!p && !q) return true;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    cout << "pass" << "\n";
}