/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
const int N = (2 * 10e4 + 10);
class Solution {
  public:
    int son[N][2], idx;
    void insert(int x) {
        int p = 0;
        for (int i = 30; i >= 0; i--) {
            int u = (x >> i) & 1;
            if (!son[p][u])
                son[p][u] = ++idx;
            p = son[p][u];
        }
    }
    int query(int x) {
        int p = 0, res = 0;
        for (int i = 30; i >= 0; i--) {
            int u = (x >> i) & 1;
            if (son[p][!u]) {
                res = res * 2 + 1;
                p = son[p][!u];
            } else {
                res = res * 2;
                p = son[p][u];
            }
        }
        return res;
    }
    int findMaximumXOR(vector<int> &nums) {
        for (auto num : nums)
            insert(num);
        int max_res = 0;
        for (auto num : nums) {
            max_res = max(query(num), max_res);
        }
        return max_res;
    }
};
// @lc code=end
