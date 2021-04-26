/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int x, int y) {
            string s_x = to_string(x);
            string s_y = to_string(y);
            return s_x + s_y > s_y + s_x;
        });
        string res = "";
        for (auto i : nums) res += to_string(i);
        for (int i = 0; i < res.size(); i ++) 
            if (res[i] != '0')
                return res.substr(i ,res.size() - i);
        return res.substr(res.size() - 1);
    }
};
// @lc code=end

