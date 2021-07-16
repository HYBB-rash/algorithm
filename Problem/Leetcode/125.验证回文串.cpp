/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

#include <algorithm>
#include <cctype>
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
    bool isPalindrome(string s) {
        string only_alpha;
        for (auto val : s) {
            if (isdigit(val)) only_alpha.push_back(val);
            if (!isalpha(val)) continue;
            only_alpha.push_back(tolower(val));
        }

        string re_only_alpha = only_alpha;
        reverse(only_alpha.begin(), only_alpha.end());
        return only_alpha == re_only_alpha;
    }
};
// @lc code=end
