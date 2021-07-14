
/**
 * *  @File        :   Acwing3482.cpp
 * *  @Time        :   2021/05/16 19:09:12
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   acwing 3481
 **/

#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1e6 + 5;

typedef long long LL;

int n;

bool f[N];

int main() {
    f[0] = 1;
    int s = 1;
    for (int i = 0;; i++) {
        for (int j = 1000000; j >= s; j--) f[j] |= f[j - s];
        if ((LL)s * (i + 1) > 1e6) break;
        s *= (i + 1);
    }
    while (cin >> n) {
        if (n < 0) return 0;
        if (n == 0)
            puts("NO");
        else
            puts(f[n] ? "YES" : "NO");
    }
}
