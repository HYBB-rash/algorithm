/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

#include <string>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
  public:
    string addBinary(string a, string b) {
        if (a.size() < b.size())
            swap(a, b);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int addition = 0;
        for (int i = 0; i < a.size(); i++) {
            int x = a[i] - '0', y = i < b.size() ? b[i] - '0' : 0;
            int sum = (x + y + addition);
            a[i] = (sum % 2) + '0';
            addition = sum / 2;
        }
        a = addition ? a + "1" : a;
        reverse(a.begin(), a.end());
        return a;
    }
};
// @lc code=end
