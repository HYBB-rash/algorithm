/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    int col_search(vector<vector<int>> &matrix, int target) {
        int l = 0, r = matrix.size() - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (matrix[mid][0] <= target) l = mid;
            else r = mid - 1;
        }
        return r;
    }
    int row_search(vector<int> &matrix, int target) {
        int l = 0, r = matrix.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (matrix[mid] >= target) r = mid;
            else l = mid + 1; 
        }
        return matrix[l];
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col = col_search(matrix, target);
        int res = row_search(matrix[col], target);
        return res == target;
    }
};
// @lc code=end

