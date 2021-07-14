/*
 * @lc app=leetcode.cn id=1190 lang=cpp
 *
 * [1190] 反转每对括号间的子串
 */

#include <algorithm>
#include <cstdio>
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
    string dfs(string &s, int &index, int flag) {
        string res;
        for (index = index + 1; index < s.size() && s[index] != ')'; index++)
            if (s[index] != '(')
                res.push_back(s[index]);
            else
                res.append(dfs(s, index, 1));
        if (flag) reverse(res.begin(), res.end());
        return res;
    }
    string reverseParentheses(string s) {
        int index = -1;
        return dfs(s, index, 0);
    }
};
// @lc code=end
