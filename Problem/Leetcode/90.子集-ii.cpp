/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    map<vector<int>, bool> map;
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(int start, vector<int> &nums) {
        if (!map[tmp]) {
            map[tmp] = true;
            res.push_back(tmp);
        }
        for (int i = start; i < nums.size(); i ++) {
            tmp.push_back(nums[i]);
            dfs(i + 1, nums);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(0, nums);
        return res;
    }
};
// @lc code=end

