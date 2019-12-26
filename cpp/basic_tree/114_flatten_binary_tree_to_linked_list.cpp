#include "../header.h"
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// DFS
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        if (root->left != nullptr) flatten(root->left);
        if (root->right != nullptr) flatten(root->right);
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = nullptr;
        while(root->right != nullptr) root = root->right;
        root->right  = temp;
    }
};

int main() {
    cout << "Hello World" << '\n';
}
