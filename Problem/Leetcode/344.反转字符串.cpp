/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
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
    void reverseString(vector<char> &s) {
        int end = s.size() / 2, len = s.size();
        for (int i = 0; i < end; i++) { swap(s[i], s[len - i - 1]); }
    }
};
// @lc code=end
