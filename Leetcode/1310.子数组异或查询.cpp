/*
 * @lc app=leetcode.cn id=1310 lang=cpp
 *
 * [1310] 子数组异或查询
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
        vector<int> f(arr.size() + 10), res;
        for (int i = 0; i < arr.size(); i++) {
            f[i + 1] = f[i] ^ arr[i];
        }
        for (auto &q : queries) {
            int start = q[0], end = q[1] + 1;
            res.push_back(f[end] ^ f[start]);
        }
        return res;
    }
};
// @lc code=end
