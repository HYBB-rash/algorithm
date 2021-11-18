// Acwing3302题 逆波兰表达式
#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <cstring>

using namespace std;

void eval(stack<int> &num, stack<char> &op) {
    int b = num.top(); num.pop();
    int a = num.top(); num.pop();
    char c = op.top(); op.pop();
    int x = 0;
    if (c == '+') x = a + b;
    else if (c == '-') x = a - b;
    else if (c == '*') x = a * b;
    else x = a / b;
    num.push(x);
}

int main () {

    unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    stack<int> num; stack<char> op;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i ++) {
        if (isdigit(s[i])) {
            int j = i, x = 0;
            while (j < s.size() && isdigit(s[j]))
                x = x * 10 + s[j ++] - '0';
            i = j - 1;
            num.push(x);
        } else if (s[i] == '(') {
            op.push(s[i]);
        } else if (s[i] == ')') {
            while(op.top() != '(') eval(num, op);
            op.pop();
        } else {
            while (op.size() && pr[op.top()] >= pr[s[i]]) eval(num, op);
            op.push(s[i]);
        }
    }
    while (op.size()) eval(num, op);
    cout << num.top() << endl;
    return 0;
}