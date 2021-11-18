
/** 
 * *  @File        :   Acwing422.cpp
 * *  @Time        :   2021/05/09 18:57:19
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   acwing 422
**/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100100;

int p[N];

void insert(int l, int r, int c) {
    p[l] += c;
    p[r + 1] -= c;
}

int main() {
    int l, m;
    cin >> l >> m;
    insert(0, l, 1);
    for (int i = 0; i < m; i++) {
        int s = 0, e = 0;
        cin >> s >> e;
        insert(s, e, -1);
    }
    int res = 0;
    for (int i = 0, tmp = 0; i <= l; i++) {
        tmp += p[i];
        if (tmp == 1) res++;
    }
    cout << res;
    return 0;
}