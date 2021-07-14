/*
 * @lc app=leetcode.cn id=1442 lang=cpp
 *
 * [1442] 形成两个异或相等数组的三元组数目
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    int f[310];
    int countTriplets(vector<int> &arr) {
        for (int i = 0; i < arr.size(); i++) {
            f[i + 1] = f[i] ^ arr[i];
        }
        int res = 0;
        for (int i = 0; i < arr.size() - 1; i++) {
            for (int k = i + 1; k < arr.size(); k++) {
                if (f[k + 1] == f[i])
                    res += k - i;
            }
        }
        return res;
    }
};
// @lc code=end
