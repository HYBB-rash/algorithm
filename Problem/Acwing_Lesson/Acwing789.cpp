
/**
 * *  @File        :   Acwing789.cpp
 * *  @Time        :   2021/05/28 13:42:38
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   Acwing 789. 二分模板题目
 **/

#include <iostream>

using namespace std;

const int N = 100100;
int q[N], n, m, t;

int b_search_right(int q[], int l, int r, int t) {
    while (l < r) {
        int mid = (l + r) >> 1;
        if (q[mid] >= t)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int b_search_left(int q[], int l, int r, int t) {
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (q[mid] <= t)
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

int main() {

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> q[i];
    for (int i = 0; i < m; i++) {
        cin >> t;
        int start = b_search_right(q, 0, n - 1, t),
            end = b_search_left(q, 0, n - 1, t);
        start = q[start] == t ? start : -1, end = q[end] == t ? end : -1;
        cout << start << " " << end << endl;
    }
    return 0;
}