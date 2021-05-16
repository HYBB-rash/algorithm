
/** 
 * *  @File        :   Acwing3485.cpp
 * *  @Time        :   2021/05/10 19:09:25
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   acwing 3485
**/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10010 * 31, M = 10010;

int s[M];
int son[N][2], cnt[N], idx;

int n, m;

void insert(int x, int v) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1;
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
        cnt[p] += v;
    }
}

int query(int x) {
    int res = 0, p = 0;
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & i;
        if (cnt[son[p][!u]])
            p = son[p][!u], res = res * 2 + 1;
        else
            p = son[p][u], res = res * 2;
    }
    return res;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s[i + 1] = s[i] ^ x;
    }
    int res = 0;
    insert(s[0], 1);
    for (int i = 1; i <= n; i++) {
        if (i > m) insert(s[i - m - 1], -1);
        res = max(query(s[i]), res);
        insert(s[i], 1);
    }
    cout << res << endl;
    return 0;

}