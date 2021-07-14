
/**
 * *  @File        :   Acwing787.cpp
 * *  @Time        :   2021/05/21 16:25:46
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   归并排序模板题,acwing787题
 **/

#include <iostream>

using namespace std;

const int N = 100100;
int q[N], tmp[N];

void merge_sort(int q[], int l, int r) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);

    int i = l, j = mid + 1, cnt = 0;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) tmp[cnt++] = q[i++];
        else tmp[cnt ++] = q[j ++];
    }
    while (i <= mid) tmp[cnt++] = q[i++];
    while (j <= r) tmp[cnt++] = q[j++];
    for (int i = l, j = 0; i <= r; i ++, j ++) q[i] = tmp[j];
}

int main() {

    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> q[i];
    merge_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++) cout << q[i] << " ";
    return 0;
}