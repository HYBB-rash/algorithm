/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode *father;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL), father(NULL) {}
 * };
 */
class Solution {
public:
    stack<TreeNode*> stk;
    TreeNode* inorderSuccessor(TreeNode* p) {
        if (p->right) {
            p = p->right;
            while (p) {
                stk.push(p);
                p = p->left;
            }
            return stk.top();
        }
        while (p->father && p == p->father->right) p = p->father;
        return p->father;
        
    }
};