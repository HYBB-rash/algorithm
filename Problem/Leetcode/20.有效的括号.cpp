/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

#include <string>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
  public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto c : s) {
            if (stk.empty())
                stk.push(c);
            else {
                if (c == '(' || c == '{' || c == '[')
                    stk.push(c);
                else {
                    char t = stk.top();
                    if (t == '(' && c == ')')
                        stk.pop();
                    else if (t == '[' && c == ']')
                        stk.pop();
                    else if (t == '{' && c == '}')
                        stk.pop();
                    else return false;
                }
            }
        }
        return stk.empty();
    }
};
// @lc code=end
