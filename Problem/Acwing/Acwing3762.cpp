
/*
 *  @File        :   Acwing3762.cpp
 *  @Time        :   2021/07/15 22:23:10
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   Acwing 3762 二进制矩阵 每日一题
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

const int N = 110;

void PP(int x, int y, int d) {
    if (d == 1)
        printf("%d %d %d %d %d %d\n", x, y, x, y + 1, x + 1, y);
    else if (d == 2)
        printf("%d %d %d %d %d %d\n", x, y, x, y - 1, x + 1, y);
    else if (d == 3)
        printf("%d %d %d %d %d %d\n", x, y, x - 1, y, x, y + 1);
    else if (d == 4)
        printf("%d %d %d %d %d %d\n", x, y, x - 1, y, x, y - 1);
}

int main() {
    int T, n, m;

    cin >> T;

    while (T--) {
        cin >> n >> m;
        int res = 0;
        char mat[N][N];

        for (int i = 1; i <= n; i++) {
            cin >> (mat[i] + 1);

            for (int j = 1; j <= m; j++) {
                if (mat[i][j] == '1') res += 3;
            }
        }

        cout << res << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (mat[i][j] == '0') continue;
                if (i < n && j < m)
                    PP(i, j, 1), PP(i, j + 1, 2), PP(i + 1, j, 3);
                else if (i == n && j == m)
                    PP(i, j, 4), PP(i - 1, j, 2), PP(i, j - 1, 3);
                else if (j == m)
                    PP(i, j, 2), PP(i, j - 1, 1), PP(i + 1, j, 4);
                else if (i == n)
                    PP(i, j, 3), PP(i - 1, j, 1), PP(i, j + 1, 4);
            }
        }
    }

    return 0;
}