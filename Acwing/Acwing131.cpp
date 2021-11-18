
/** 
 * *  @File        :   Acwing131.cpp
 * *  @Time        :   2021/05/18 14:43:07
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   acwing131
**/

#include <iostream>
#include <cstdio>

using namespace std;

const int N = 100100;
int stk[N], index[N], idx = 0;

int main() {
    int n;
    while (cin >> n, n) {
        int x, res = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            while (idx && stk[idx] > x) idx--;
            for (int j = 1; j <= idx; j++) {
                res = max((i - index[j] + 1) * stk[j], res);
            }
            stk[++idx] = x, index[idx] = i;
        }
        cout << res << endl;
        idx = 0;
    }
    return 0;
}