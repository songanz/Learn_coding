#include "header.h"
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
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return root;
    if (key > root->val) {
      root->right = deleteNode(root->right, key);  // 搜右面
    } else if (key < root->val) {
      root->left = deleteNode(root->left, key);  // 搜左边
    } else {
      if (root->left != nullptr && root->right != nullptr) {  // 两边都有子列
        TreeNode* min = root->right;
        while (min->left != nullptr) min = min->left;
        root->val = min->val;  // 用右面的min值替代root val
        root->right = deleteNode(root->right, min->val);  // 在右列中删掉node
      } else {  // 有一边没有子列
        TreeNode* new_root = root->left == nullptr ? root->right : root->left;
        root->left = root->right = nullptr;  // avoid recursive deconstruct
        delete root;  // 释放
        return new_root;
      }
    }    
    return root;
  }
};

int main() {
    cout << "pass" << "\n";
}