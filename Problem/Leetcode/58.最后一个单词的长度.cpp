/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
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
    int lengthOfLastWord(string s) {
        if (s.back() != ' ') s.push_back(' ');

        int res = 0;
        for (int i = 0, j = 0; i < s.size(); i++) {
            if (s[i] != ' ') continue;
            res = i - j == 0 ? res : i - j;
            j = i + 1;
        }

        return res;
    }
};
// @lc code=end
