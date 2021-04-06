/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int p = 0, i = 2; i < nums.size(); i ++, p ++) {
            if (nums[p] == nums[i]) {
                nums.erase((nums.begin() + i));
                p --, i --;
            }
        }/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int p = 0, i = 2; i < nums.size(); i ++, p ++) {
            if (nums[p] == nums[i]) {
                nums.erase((nums.begin() + i));
                p --, i --;
            }
        }
        return nums.size();
    }
};
// @lc code=end


        return nums.size();
    }
};
// @lc code=end

