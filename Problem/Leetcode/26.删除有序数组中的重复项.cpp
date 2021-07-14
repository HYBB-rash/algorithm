/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        for (int i = 1; i < nums.size(); i++) {
            while (i - 1 >= 0 && i < nums.size() && nums[i] == nums[i - 1])
                nums.erase(nums.begin() + i);
        }
        return nums.size();
    }
};
// @lc code=end
