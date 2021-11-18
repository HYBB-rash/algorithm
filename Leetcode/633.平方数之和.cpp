/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long i = 0; i * i <= c; i ++) {
            long cul = c - i * i;
            int tmp = sqrt(cul);
            if (tmp * tmp == cul) return true;
        }
        return false;
    }
};
// @lc code=end

