#include "../header.h"
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        int max_l = height(root->left); 
        int max_r = height(root->right); 
        // 小心，这里子列也必须是balanced
        return (abs(max_l - max_r)<=1) && isBalanced(root->left) && isBalanced(root->right);
    }
private:
    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
};

int main() {
    Solution s;
    TreeNode root(1);
    TreeNode t1(2);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode t4(3);
    TreeNode t5(4);
    TreeNode t6(4);
    root.left = &t1;
    root.right = &t2;
    t1.left = &t3;
    t1.right = &t4;
    t3.left = &t5;
    t3.right = &t6;

    cout << s.isBalanced(&root) << endl;
}