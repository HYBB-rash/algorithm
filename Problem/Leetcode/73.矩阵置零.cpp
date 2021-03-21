/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // TODO总结思路
        int row = 0, col = 0;
        for (int i = 0; i < matrix.size(); i ++) {
            if (matrix[i][0] == 0) row ++;
        }
        for (int j = 0; j < matrix[0].size(); j ++) {
            if (matrix[0][j] == 0) col ++;
        }
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 1; i < n; i ++) {
            for (int j = 1; j < m; j ++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < n; i ++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < m; j ++) 
                    matrix[i][j] = 0;
            }
        }
        for (int j = 1; j < m; j ++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < n; i ++)
                    matrix[i][j] = 0;
            }
        }
        if (row >= 1) 
            for (int i = 0; i < n; i ++) matrix[i][0] = 0;
        if (col >= 1)
            for (int j = 0; j < m; j ++) matrix[0][j] = 0;
    }
};
// @lc code=end

