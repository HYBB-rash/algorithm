/*
 * @lc app=leetcode.cn id=1486 lang=cpp
 *
 * [1486] 数组异或操作
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    int calc(int x) {
        if (x % 4 == 0)
            return x;
        else if (x % 4 == 1)
            return 1;
        else if (x % 4 == 2)
            return x + 1;
        else
            return 0;
    }
    int xorOperation(int n, int start) {
        int s = start >> 1;
        int prefix = calc(s - 1) ^ calc(s + n - 1);
        int last = n & start & 1;
        int ans = prefix << 1 | last;
        return ans;
    }
};
// @lc code=end
