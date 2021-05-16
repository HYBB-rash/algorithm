/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
  public:
    int romanToInt(string s) {
        unordered_map<char, int> nums = {{'I', 1},   {'V', 5},   {'X', 10},
                                         {'L', 50},  {'C', 100}, {'D', 500},
                                         {'M', 1000}};
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            int value = nums[s[i]];
            if (i + 1 < s.size() && nums[s[i + 1]] > value)
                value = -value;
            res += value;
        }
        return res;
    }
};
// @lc code=end
