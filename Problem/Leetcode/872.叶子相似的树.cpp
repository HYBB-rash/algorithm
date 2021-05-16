/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
#include <vector>
using namespace std;

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
    void dfs_get_leafs(TreeNode *root, vector<int> &leafs) {
        if (root == nullptr)
            return;
        dfs_get_leafs(root->left, leafs);
        if (root->left == nullptr && root->right == nullptr)
            leafs.push_back(root->val);
        dfs_get_leafs(root->right, leafs);
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        vector<int> root_leaf1, root_leaf2;
        dfs_get_leafs(root1, root_leaf1);
        dfs_get_leafs(root2, root_leaf2);
        return root_leaf1 == root_leaf2;
    }
};
// @lc code=end
