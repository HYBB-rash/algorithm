/*
 * @lc app=leetcode.cn id=1877 lang=cpp
 *
 * [1877] 数组中最大数对和的最小值
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
    int minPairSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int max_val = 0, len = nums.size();
        for (int i = 0; i < len / 2; i++) {
            max_val = max(max_val, nums[i] + nums[len - 1 - i]);
        }
        return max_val;
    }
};
// @lc code=end
