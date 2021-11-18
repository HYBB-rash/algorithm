/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        vector<int> nums;
        for (; x; x /= 10)
            nums.push_back(x % 10);
        for (int i = 0; i < nums.size() >> 1; i++) {
            int head = i, tail = nums.size() - 1 - i;
            if (nums[head] != nums[tail]) return false;
        }
        return true;
    }
};
// @lc code=end
