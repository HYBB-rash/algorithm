/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 二叉树的堂兄弟节点
 */

#include <sys/types.h>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  public:
    TreeNode *find(TreeNode *root, int target, int &k, int deep) {
        if (root == nullptr || root->val == target)
            return nullptr;
        if ((root->left != nullptr && root->left->val == target) ||
            (root->right != nullptr && root->right->val == target)) {
            k = deep;
            return root;
        }
        TreeNode *res = find(root->left, target, k, deep + 1);
        return res == nullptr ? find(root->right, target, k, deep + 1) : res;
    }
    bool isCousins(TreeNode *root, int x, int y) {
        int k_x = 0, k_y = 0;
        TreeNode *left = find(root, x, k_x, 1);
        TreeNode *right = find(root, y, k_y, 1);
        return k_x == k_y && left != right;
    }
};
// @lc code=end
