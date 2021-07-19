/*
 * @lc app=leetcode.cn id=1838 lang=cpp
 *
 * [1838] 最高频元素的频数
 */

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    int maxFrequency(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        long long total = 0;
        int l = 0, res = 1;
        for (int r = 1; r < n; ++r) {
            total += (long long)(nums[r] - nums[r - 1]) * (r - l);
            while (total > k) {
                total -= nums[r] - nums[l];
                ++ l;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
// @lc code=end
