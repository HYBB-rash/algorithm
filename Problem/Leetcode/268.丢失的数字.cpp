/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
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
    int missingNumber(vector<int> &nums) {
        int n = nums.size(), target = 0;
        for (int i = 0; i <= n; i++) target += i;

        for (auto val : nums) target -= val;
        return target;
    }
};
// @lc code=end
