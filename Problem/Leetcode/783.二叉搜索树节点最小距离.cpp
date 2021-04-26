/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
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
    int minDiffInBST(TreeNode* root) {
        stack<TreeNode*> stk;
        for (auto p = root; p != nullptr; p = p->left) stk.push(p);
        int start = 0x3f3f3f3f, res = 0x3f3f3f3f;
        while (stk.size()) {
            auto t = stk.top();
            stk.pop();
            if(t->right != nullptr)
                for (auto p = t->right; p != nullptr; p = p->left) stk.push(p);
            res = min(abs(start - t->val), res);
            start = t->val;
        }
        return res;
    }
};
// @lc code=end

