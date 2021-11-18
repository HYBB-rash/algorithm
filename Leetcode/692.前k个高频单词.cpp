/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */

#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    static bool cmp(pair<string, int> a, pair<string, int> b) {
        if (a.second != b.second)
            return a.second > b.second;
        return a.first < b.first;
    }
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> record;
        for (auto w : words) {
            record[w]++;
        }
        vector<pair<string, int>> res(record.begin(), record.end());
        sort(res.begin(), res.end(), cmp);
        vector<string> ans(k);
        for (int i = 0; i < k; i++) {
            ans[i] = res[i].first;
        }
        return ans;
    }
};
// @lc code=end
