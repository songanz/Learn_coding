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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int max_l = maxDepth(root->left);
        int max_r = maxDepth(root->right);
        return max(max_l, max_r) + 1;
    }
};

int main() {
    cout << "pass" << "\n";
}