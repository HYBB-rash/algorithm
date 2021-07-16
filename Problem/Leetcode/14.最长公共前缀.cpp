/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "";

        int son[210][30] = {}, idx = 0, cnt_g[210] = {};

        for (auto str : strs) {
            int p = 0;
            if (str == "") return "";
            for (auto c : str) {
                int u = c - 'a';
                if (!son[p][u]) son[p][u] = ++idx;
                p = son[p][u];
                cnt_g[p]++;
            }
        }

        string res = "";
        int p = 0;
        while (true) {
            int cnt = 0;
            pair<char, int> node;
            for (int i = 0; i < 26; i++) {
                if (!son[p][i]) continue;
                cnt++;
                node.first = i + 'a', node.second = son[p][i];
            }
            
            p = node.second;
            if (cnt == 0 || cnt > 1 || cnt_g[p] != strs.size()) break;
            res.push_back(node.first);
        }
        return res;
    }
};
// @lc code=end
