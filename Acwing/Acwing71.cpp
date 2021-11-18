/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int treeDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = treeDepth(root->left);
        int right = treeDepth(root->right);
        return max(left, right) + 1;
    }
};