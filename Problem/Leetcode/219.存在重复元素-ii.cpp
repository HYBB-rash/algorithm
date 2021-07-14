/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
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
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < nums.size(); i++) {
            for (auto n : m[nums[i]]) {
                if (abs(n - i) <= k) return true;
            }
            m[nums[i]].push_back(i);
        }
        return false;
    }
};
// @lc code=end
