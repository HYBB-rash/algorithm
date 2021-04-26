/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        vector<int> ne(needle.size());
        ne[0] = -1;
        for (int i = 1, j = -1; i < needle.size(); i ++) {
            while (j >= 0 && needle[j + 1] != needle[i]) j = ne[j];
            if (needle[i] == needle[j + 1]) j ++;
            ne[i] = j;
        }
        for (int i = 0, j = -1; i < haystack.size(); i ++) {
            while (j >= 0 && needle[j + 1] != haystack[i]) j = ne[j];
            if (haystack[i] == needle[j + 1]) j ++;
            if (j == needle.size() - 1) return i - needle.size() + 1;
        }
        return -1;
    }
};
// @lc code=end

