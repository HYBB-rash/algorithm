/*
 * @lc app=leetcode.cn id=1074 lang=cpp
 *
 * [1074] 元素和为目标值的子矩阵数量
 */

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  private:
    int subarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (auto &x : nums) {
            pre += x;
            if (mp.find(pre - k) != mp.end()) count += mp[pre - k];
            mp[pre]++;
        }
        return count;
    }

  public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
        int ans = 0;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            vector<int> sum(n);
            for (int j = i; j < m; ++j) {
                for (int c = 0; c < n; ++c) sum[c] += matrix[j][c];
                ans += subarraySum(sum, target);
            }
        }
        return ans;
    }
};
// @lc code=end
