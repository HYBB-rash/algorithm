/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    vector<int> plusOne(vector<int> &digits) {
        int add = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            add = digits[i] + add;
            digits[i] = add % 10;
            add /= 10;
        }
        if (add) digits.insert(digits.begin(), add);
        return digits;
    }
};
// @lc code=end
