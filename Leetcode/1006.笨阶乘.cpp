/*
 * @lc app=leetcode.cn id=1006 lang=cpp
 *
 * [1006] 笨阶乘
 */
// @lc code=start
class Solution {
public:
    // stack<int> nums;
    // stack<char> op;
    // unordered_map<char, int> pri{{'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}};
    // void compute() {
    //     int res = 0;
    //     int b = nums.top(); nums.pop();
    //     int a = nums.top(); nums.pop();
    //     char opt = op.top(); op.pop();
    //     if (opt == '+') res = a + b;
    //     else if (opt == '-') res = a - b;
    //     else if (opt == '*') res = a * b;
    //     else if (opt == '/') res = a / b;
    //     nums.push(res);
    // }
    int clumsy(int N) {
        // nums.push(N);
        // for (int i = 1; i < N; i ++) {
        //     char opt;
        //     if (i % 4 == 1) opt = '*';
        //     else if (i % 4 == 2) opt = '/';
        //     else if (i % 4 == 3) opt = '+';
        //     else opt = '-';
        //     while (op.size() && pri[op.top()] >= pri[opt]) compute();
        //     op.push(opt);
        //     nums.push(N - i);
        // }
        // while (op.size()) compute();
        // return nums.top();
        int map[5] = {0, 1, 2, 6, 7};
        if (N <= 4) return map[N];
        if (N % 4 == 0) return N + 1;
        if (N % 4 <= 2) return N + 2;
        return N - 1;
    }
};
// @lc code=end

