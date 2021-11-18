/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        map<int, bool> records;
        for (auto val : nums1) records[val] = true;

        set<int> res;
        for (auto val : nums2)
            if (records[val]) res.insert(val);
        vector<int> rest(res.begin(), res.end());

        return rest;
    }
};
// @lc code=end

int main() {
    Solution s;

    vector<int> a = {4, 9, 5}, b = {9, 4, 9, 8, 4};

    vector<int> res = s.intersection(a, b);

    for (auto val : res) cout << val << " ";
    cout << endl;

    return 0;
}