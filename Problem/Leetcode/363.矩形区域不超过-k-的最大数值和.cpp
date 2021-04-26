/*
 * @lc app=leetcode.cn id=363 lang=cpp
 *
 * [363] 矩形区域不超过 K 的最大数值和
 */

// @lc code=start
class Solution {
public:
    int sum_ma[210][210];
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int max_ans = -1e7;
        for (int i = 1; i <= matrix.size(); i ++) {
            for (int j = 1; j <= matrix[0].size(); j ++) {
                sum_ma[i][j] = sum_ma[i - 1][j] + sum_ma[i][j - 1] + matrix[i - 1][j - 1] - sum_ma[i - 1][j - 1];
            }
        }
        for (int i = 1; i <= matrix.size(); i ++) {
            for (int j = 1; j <= matrix[0].size(); j ++) {
                for (int a = 0; a < i; a ++) {
                    for (int b = 0; b < j; b ++) {
                        int cnt = sum_ma[a][b] - sum_ma[a][j] - sum_ma[i][b] + sum_ma[i][j];
                        if (cnt <= k) max_ans = max(cnt, max_ans);
                    }
                }
            }
        }
        return max_ans;
    }
};
// @lc code=end

