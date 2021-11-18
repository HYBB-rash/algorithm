/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序查找树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *ans_root = nullptr, *p = nullptr;
    TreeNode* increasingBST(TreeNode* root) {
        if (root == nullptr) return ans_root;
        increasingBST(root->left);
        root->left = nullptr;
        if (ans_root == nullptr) {
            ans_root = root;
            p = ans_root;
        } else {
            p->right = root;
            p = p->right;
        }
        increasingBST(root->right);
        return ans_root;
    }
};
// @lc code=end

