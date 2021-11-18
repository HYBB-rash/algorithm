
/* 
 *  @File        :   Acwing3761.cpp
 *  @Time        :   2021/07/15 21:35:28
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   Acwing 3761 唯一最小数 每日一题
 */

#include <iostream>
#include <utility>
#include <vector>
#include <limits.h>

using namespace std;

const int N = 100010;

int main() {

    int T, n;
    cin >> T;

    while (T--) {

        cin >> n;

        vector<pair<int, int>> list(n);
        int records[N] = {};

        for (int i = 0; i < n; i++) {
            cin >> list[i].first;
            list[i].second = i + 1;
            records[list[i].first] ++;
        }

        int min = INT_MAX, res = -1;
        for (int i = 0; i < n; i++) {
            if (records[list[i].first] != 1) continue;
            if (min > list[i].first) {
                min = list[i].first;
                res = list[i].second;
            }
        }

        cout << res << "\n";
    }

    return 0;
}