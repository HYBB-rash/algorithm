
/**
 * *  @File        :   Acwing785.cpp
 * *  @Time        :   2021/05/21 16:11:33
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   快速排序模板题,Acwing785题
 **/

#include <iostream>

using namespace std;

const int N = 100100;
int q[N];

void quick_sort(int q[], int l, int r) {

    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[(l + r) >> 1];
    while (i < j) {
        do { i++; } while (x > q[i]);
        do { j--; } while (x < q[j]);
        if (i < j) swap(q[i], q[j]);
    }

    quick_sort(q, l, j), quick_sort(q, j + 1, r);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> q[i];
    quick_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++) cout << q[i] << " ";
    return 0;
}