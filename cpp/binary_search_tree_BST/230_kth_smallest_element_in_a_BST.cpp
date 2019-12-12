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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        inorderTraverse(root, arr);
        return arr[k-1];
    }
private: 
    void inorderTraverse(TreeNode* root, vector<int>& arr) {
        if (!root) return;
        inorderTraverse(root->left, arr);
        arr.push_back(root->val);
        inorderTraverse(root->right, arr);
        return;        
    }
};

int main() {
    cout << "pass" << "\n";
}