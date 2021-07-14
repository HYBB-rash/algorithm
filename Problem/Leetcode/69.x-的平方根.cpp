/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
  public:
    int mySqrt(int x) {
        int l = 0, r = x, ans = 0;
        while (l <= r) {
            int mid = ((r - l) >> 1) + l;
            if ((long long)mid * mid <= x) {
                l = mid + 1;
                ans = mid;
            } else
                r = mid - 1;
        }
        return ans;
    }
};
// @lc code=end
