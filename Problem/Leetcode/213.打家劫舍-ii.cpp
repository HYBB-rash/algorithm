/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), INF = 1e8;
        if (n == 1) return nums[0];
        vector<vector<int>> f(n, vector<int>(2, 0));
        f[0][0] = -INF, f[0][1] = nums[0];
        for (int i = 1; i < n; i ++) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            f[i][1] = f[i - 1][0] + nums[i];
        }
        int res = f[n - 1][0];
        f[0][0] = 0, f[0][1] = -INF;
        for (int i = 1; i < n; i ++) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            f[i][1] = f[i - 1][0] + nums[i];
        }
        return max(res, max(f[n - 1][0], f[n - 1][1]));
    }
};
// @lc code=end

