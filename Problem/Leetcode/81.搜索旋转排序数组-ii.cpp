/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for (auto v : nums) {
            if (target == v) return true;
        }
        return false;
    }
};
// @lc code=end

