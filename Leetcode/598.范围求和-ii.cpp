/*
 * @lc app=leetcode.cn id=598 lang=cpp
 *
 * [598] 范围求和 II
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
  public:
    int maxCount(int m, int n, vector<vector<int>> &ops) {
        for (auto o : ops) {
            m = min(m, o[0]);
            n = min(n, o[1]);
        }
        return m * n;
    }
};
// @lc code=end
