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
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
private:
    bool isMirror(TreeNode *t1, TreeNode *t2) {
        if (t1==NULL && t2==NULL) return true;
        if (t1==NULL ^ t2==NULL) return false;
        return (t1->val == t2->val) && 
        isMirror(t1->left, t2->right) && 
        isMirror(t1->right, t2->left);
    }
};

int main() {
    Solution s;
    TreeNode root(1);
    TreeNode t1(2);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode t4(4);
    TreeNode t5(4);
    TreeNode t6(3);
    root.left = &t1;
    root.right = &t2;
    t1.left = &t3;
    t1.right = &t4;
    t2.left = &t5;
    t2.right = &t6;

    cout << s.isSymmetric(&root) << endl;
}