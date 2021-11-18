/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        for (auto t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int b = num.top(); num.pop();
                int a = num.top(); num.pop();
                int x = 0;
                if (t == "+") x = a + b;
                else if (t == "-") x = a - b;
                else if (t == "*") x = a * b;
                else if (t == "/") x = a / b;
                num.push(x);
            } else {
                int x = 0, rev = 1;
                if (t[0] == '-') {
                    rev = -1;
                    t = t.substr(1, t.size() - 1);
                }
                for (char c : t) x = x * 10 + c - '0';
                num.push(x * rev);
            }
        }
        return num.top();
    }
};
// @lc code=end

