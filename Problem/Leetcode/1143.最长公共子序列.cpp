/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> matrix(text2.size() + 1, vector<int>(text1.size() + 1, 0));
        for (int i = 1; i <= text2.size(); i ++) {
            for (int j = 1; j <= text1.size(); j ++) {
                if (text2[i - 1] == text1[j - 1])
                    matrix[i][j] = max(matrix[i - 1][j - 1] + 1, max(matrix[i - 1][j], matrix[i][j - 1]));
                else matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
        return matrix[text2.size()][text1.size()];
    }
};
// @lc code=end

