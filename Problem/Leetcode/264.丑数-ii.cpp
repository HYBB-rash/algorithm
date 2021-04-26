/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(1, 1);
        int i = 0, j = 0, k = 0;
        while (-- n) {
            int num = min(res[i] * 2, min(res[j] * 3, res[k] * 5));
            res.push_back(num);
            if (num % 2 == 0) i ++;
            if (num % 3 == 0) j ++;
            if (num % 5 == 0) k ++;
        }
        return res.back();
    }
};
// @lc code=end

