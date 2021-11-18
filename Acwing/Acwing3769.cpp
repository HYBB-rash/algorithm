
/*
 *  @File        :   Acwing3769.cpp
 *  @Time        :   2021/07/17 08:24:24
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   3769. 移动石子 Acwing 每日一题
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 110;
int num[N] = {};

int main() {

    int T;
    cin >> T;
    while (T--) {
        int n, d;
        cin >> n >> d;

        for (int i = 0; i < n; i++) cin >> num[i];

        int res = num[0];
        for (int i = 1; i < n  && d; i++) {
            int addition = num[i] * i;
            res += addition > d ? d / i : addition / i;
            d -= addition > d ? d : addition;
        }

        cout << res << endl;
    }

    return 0;
}