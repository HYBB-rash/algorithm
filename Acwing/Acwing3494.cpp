
/**
 * *  @File        :   Acwing3494.cpp
 * *  @Time        :   2021/05/11 19:05:19
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   acwing 3493
 **/

#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100100;

long long nums[N], status[N];
long long s[N];

int n, k;

int main() {
    cin >> n >> k;

    long long sum_on = 0;
    for (int i = 0; i < n; i++) cin >> nums[i];
    for (int i = 0; i < n; i++) {
        cin >> status[i];
        if (status[i] == 1) sum_on += nums[i];
    }
    for (int i = 0; i < n; i++) s[i + 1] = s[i] + (status[i] ? 0 : nums[i]);

    long long res = 0;
    for (int i = 0; i < n - k; i++) {
        int start = i, end = i + k;
        res = max(res, (s[end] - s[start] + sum_on));
    }

    cout << res;
    return 0;
}