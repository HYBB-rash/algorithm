/** 
 * *  @File        :   Acwing47.cpp
 * *  @Time        :   2021/04/25 20:07:03
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   acwing47 每日一题
**/

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

    vector<int> tmp;
    vector<vector<int>> ans;
    vector<vector<int>> findPath(TreeNode* root, int sum) {
        if (root == nullptr) return ans;
        tmp.push_back(root->val);
        if (root->val == sum) 
            if (!root->left && !root->right)
                ans.push_back(tmp);
        findPath(root->left, sum - root->val);
        findPath(root->right, sum - root->val);
        tmp.pop_back();
        return ans;
    }
};