#include "header.h"
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
  bool hasPathSum(TreeNode* root, int sum) {
    if (!root) return false;
    if (!root->left && !root->right) return root->val==sum;
    int new_sum = sum - root->val;
    return hasPathSum(root->left, new_sum) || hasPathSum(root->right, new_sum);
  }
};

int main() {
    Solution s;
    TreeNode root(5);
    TreeNode t1(4);
    TreeNode t2(8);
    TreeNode t3(11);
    TreeNode t4(13);
    TreeNode t5(4);
    TreeNode t6(7);
    TreeNode t7(2);
    TreeNode t8(1);
    root.left = &t1;
    root.right = &t2;

    t1.left = &t3;

    t2.left = &t4;
    t2.right = &t5;

    t3.left = &t6;
    t3.right = &t7;

    t5.right = &t8;

    cout << s.hasPathSum(&root, 22) << endl;
}