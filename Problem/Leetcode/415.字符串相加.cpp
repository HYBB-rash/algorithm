/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
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
    string addStrings(string num1, string num2) {
        int    addition = 0;
        string ans;
        for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0;
             i--, j--) {
            int a = i >= 0 ? num1[i] - '0' : 0, b = j >= 0 ? num2[j] - '0' : 0;
            addition = addition + a + b;
            ans.push_back(addition % 10 + '0');
            addition /= 10;
        }
        if (addition) ans.push_back(addition + '0');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
