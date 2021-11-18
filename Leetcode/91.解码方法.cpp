/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int cnt = 0;
    int numDecodings(string s) {
        vector<int> f(s.size() + 1 , 0);
        f[0] = 1;
        if (s.size() >= 1) {
            if (s[0] == '0') f[1] = 0;
            if (s[0] >= '1' && s[0] <= '9') f[1] = 1;
        }
        if (s.size() >= 2) {
            if (s[0] == '0') f[2] = 0;
            else {
                int tmp = (s[0] - '0') * 10 + (s[1] - '0');
                if (tmp >= 10 && tmp <= 26) f[2] = 1;
                else f[2] = 0;
                if (s[1] != '0') f[2]++;
            }
        }
        for (int i = 3; i <= s.size(); i ++) {
            int tmp = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (s[i - 1] == '0') {
                if (tmp >= 10 && tmp <= 26) f[i] = f[i - 2];
                else f[i] = 0;
            }else {
                f[i] = f[i - 1];
                if (tmp >= 10 && tmp <= 26) f[i] += f[i - 2];
            }
        }
        return f[s.size()];
    }
};
// @lc code=end

