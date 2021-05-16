/*
 * @lc app=leetcode.cn id=1269 lang=cpp
 *
 * [1269] 停在原地的方案数
 */
#include <algorithm>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
  public:
    long long dp[1010][510];
    long long mod = 10e8 + 7;
    int numWays(int steps, int arrLen) {
        dp[1][0] = 1;
        int max_col = min(steps, arrLen);
        for (int j = 1; j <= steps; j++) {
            for (int i = 1; i <= max_col; i++) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i + 1][j - 1] + dp[i][j - 1]) % mod;
            }
        }
        return dp[1][steps];
    }
};
// @lc code=end
