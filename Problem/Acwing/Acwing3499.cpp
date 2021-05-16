
/**
 * *  @File        :   Acwing3499.cpp
 * *  @Time        :   2021/05/12 19:35:12
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   acwing 3499
 **/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 210;
int n, k, m;
int a[N], w[N][N];
int f[N][N];

int main() {
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) scanf("%d", &w[i][j]);
    memset(f, -0x3f, sizeof f);

    f[1][0] = 0;
    for (int i = 2; i <= m; i++)
        for (int j = 0; j <= k; j++)
            for (int u = 1; u < i; u++)
                if (j >= i - u - 1)
                    f[i][j] =
                        max(f[i][j], f[u][j - (i - u - 1)] + w[a[u]][a[i]]);

    int res = 0;
    for (int i = 0; i <= k; i++) res = max(res, f[m][i]);

    printf("%d\n", res);
    return 0;
}