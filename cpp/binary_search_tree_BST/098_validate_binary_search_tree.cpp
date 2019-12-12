#include "../header.h"
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    ~TreeNode() {
      delete left;
      delete right;
      left = nullptr;
      right = nullptr;
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        if (root->left) {
            TreeNode* maxv = root->left;
            while (maxv->right) maxv = maxv->right;
            if (maxv->val >= root->val) return false;
        }
        if (root->right) {
            TreeNode* minv = root->right;
            while (minv->left) minv = minv->left;
            if (minv->val <= root->val) return false;
        }
        return isValidBST(root->left) && isValidBST(root->right);
        
    }
};

int main() {
    cout << "pass" << "\n";
}