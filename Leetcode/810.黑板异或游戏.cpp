/*
 * @lc app=leetcode.cn id=810 lang=cpp
 *
 * [810] 黑板异或游戏
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    bool xorGame(vector<int> &nums) {
        if (nums.size() % 2 == 0) return true;
        int sum = 0;
        for (auto num : nums) sum ^= num;
        return sum == 0;
    }
};
// @lc code=end
