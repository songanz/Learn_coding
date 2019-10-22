#include "header.h"
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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (root->left == nullptr && root->right == nullptr) return 1;
        int min_l = root->left ? minDepth(root->left) : INT32_MAX;
        int min_r = root->right ? minDepth(root->right) : INT32_MAX;
        return min(min_l, min_r) + 1;
        
    }
};

int main() {
    Solution s;
    TreeNode root(1);
    TreeNode t1(2);
    
    root.left = &t1;
    
    cout << s.minDepth(&root) << endl;
}