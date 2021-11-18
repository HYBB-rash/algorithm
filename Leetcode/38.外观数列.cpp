/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
  public:
    string countAndSay(int n) {
        string str = "1", res = "";
        for (int i = 1; i < n; i++) {
            str += "&", res = "";
            for (int i = 1, j = 0; i < str.size(); i++) {
                if (str[i] != str[j]) {
                    res += to_string(i - j) + str[j];
                    j = i;
                }
            }
            str = res;
        }
        return str;
    }
};
// @lc code=end
