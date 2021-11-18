/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        long long tmp = x;
        long long ans = 0;
        while (tmp) {
            ans = ans * 10 + tmp % 10;
            tmp /= 10;
        }
        if (abs(ans) > INT_MAX) return 0;
        return ans;
    }
};
// @lc code=end

