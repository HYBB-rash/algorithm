
/*
 *  @File        :   Acwing3773.cpp
 *  @Time        :   2021/07/19 21:33:43
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   3773. 兔子跳 Acwing 每日一题
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

const int N = 100010;
int list[N];

int main() {
    int T;
    cin >> T;
    while (T--) {

        int n, x;
        cin >> n >> x;
        for (int i = 0; i < n; i++) cin >> list[i];

        bool flag = false;
        int a = 0;
        for (int i = 0; i < n; i++) {
            if (list[i] == x) flag = true;
            a = max(list[i], a);
        }

        if (flag)
            cout << "1" << endl;
        else if (a > x)
            cout << "2" << endl;
        else
            cout << (x + a - 1) / a << endl;
    }

    return 0;
}