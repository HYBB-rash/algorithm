/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
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
    bool containsDuplicate(vector<int> &nums) {
        unordered_map<int, int> m;
        for (auto num : nums) {
            m[num]++;
            if (m[num] == 2) return true;
        }
        return false;
    }
};
// @lc code=end
