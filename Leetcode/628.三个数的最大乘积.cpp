/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 */

// @lc code=start
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        if (nums[0] < 0 && nums[0] < 0) {
            ans = nums[0] * nums[1] * nums[nums.size() - 1];
        }
        ans = max(nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3], ans);
        return ans;
    }
    int maximumProductBySet(vector<int>& nums) {
        // 还有一种并查集做法
        return 0;
    }
};
// @lc code=end

