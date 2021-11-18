
/*
 *  @File        :   Acwing3763.cpp
 *  @Time        :   2021/07/16 11:31:23
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   3763. 数字矩阵 Acwing 每日一题
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits.h>
#include <string>
#include <vector>

using namespace std;

const int N = 20;

int main() {

    int T, n, m;
    cin >> T;
    while (T--) {

        cin >> n >> m;

        int min_val = INT_MAX, odd_cnt = 0, res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int val = 0;
                cin >> val;

                if (val <= 0) { odd_cnt++; }
                min_val = min(min_val, abs(val));

                res += abs(val);
            }
        }

        res = odd_cnt % 2 ? res - 2 * min_val : res;
        cout << res << endl;
    }

    return 0;
}